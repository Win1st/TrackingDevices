#include <SPI.h>
#include <RadioLib.h>
#include <math.h>

#define CS_PIN    10
#define GDO0_PIN  38
#define GDO2_PIN  39
#define SCK_PIN   36
#define MISO_PIN  37
#define MOSI_PIN  35
#define RST_PIN   -1
#define BTN_PIN   15

SPIClass newSPI(HSPI);
CC1101 cc1101 = new Module(CS_PIN, GDO0_PIN, RST_PIN, GDO2_PIN,
                           newSPI, SPISettings(2000000, MSBFIRST, SPI_MODE0));

byte rxBuffer[16];
bool isPressed = false;

float approximateDistanceCalc(int rssi) {
  float exponent = (10.0f - (float)rssi - 40.0f) / 20.0f;
  float distance = pow(10.0f, exponent);
  return (distance < 0) ? 0 : distance;
}

void printRxBuffer(const byte* buffer, int len) {
  Serial.print("Raw response (HEX): ");
  String hexString = "";               // สร้างตัวแปร String สำหรับเก็บค่าที่จะแสดง
    for (int i = 0; i < len; i++) {
    hexString += String(buffer[i], HEX); // แปลงค่าของ buffer[i] เป็น String ในรูปแบบ HEX แล้วนำมาต่อกับ hexString
    hexString += " ";                  // ต่อช่องว่างหลังจากแต่ละค่า
    }
  Serial.println(hexString);           // พิมพ์ผลลัพธ์ที่เก็บไว้ใน hexString
  Serial.println();
}

void setup() {
  Serial.begin(9600);
  Serial.println("Master code with XOR-based request and 5-second countdown.");
  
  pinMode(BTN_PIN, INPUT_PULLUP);
  newSPI.begin(SCK_PIN, MISO_PIN, MOSI_PIN, CS_PIN);
  
  int state = cc1101.begin();
  if (state == RADIOLIB_ERR_NONE) {
    Serial.println("CC1101 initialized successfully.");
  } else {
    Serial.print("CC1101 initialization failed, code ");
    Serial.println(state);
    while(true){ delay(10); }
  }
  
  cc1101.setFrequency(433.92);
  cc1101.setBitRate(4.8);
  cc1101.setOutputPower(10);
  cc1101.setSyncWord(0x2D, 0xD4);
  cc1101.setCrcFiltering(true);
  cc1101.setOOK(true);
  
  state = cc1101.setNodeAddress(0x01, 1);
  if (state == RADIOLIB_ERR_NONE) {
    Serial.println("Node address set successfully.");
  } else {
    Serial.print("Failed to set node address, code ");
    Serial.println(state);
    while(true){ delay(10); }
  }
  
  Serial.println("Press the button to send 'Track' packet.");
}

void loop() {
  if(digitalRead(BTN_PIN) == LOW && !isPressed) {
    isPressed = true;
    
    byte payload[10] = {0xAA, 0x01, 0x01, 'T', 'r', 'a', 'c', 'k', 0, 0};
    byte checksum = 0;
    for(int i = 0; i < 8; i++){
      checksum ^= payload[i];
    }
    payload[8] = checksum;
    payload[9] = 0x55;
    
    Serial.print("TRANSMIT: ");
    for (int i = 0; i < 10; i++){
      Serial.print(payload[i], HEX);
      Serial.print(" ");
    }
    Serial.println();
    
    int state = cc1101.transmit(payload, sizeof(payload));  // ประกาศตัวแปร state ที่นี่
    if(state == RADIOLIB_ERR_NONE) {
      cc1101.finishTransmit();
      Serial.println("Packet sent. Switching to RX mode...");
    } else {
      Serial.print("Transmission failed, code ");
      Serial.println(state);
    }
    
    cc1101.startReceive();
    
    unsigned long startTime = millis();
    bool gotResponse = false;
    int countdown = 5;
    unsigned long nextPrint = millis() + 1000;
    Serial.println(millis());
    
    Serial.println("Entering response loop...");
while(millis() - startTime < 5000) {
  if(cc1101.readData(rxBuffer, sizeof(rxBuffer)) == RADIOLIB_ERR_NONE) {
    printRxBuffer(rxBuffer, 7);
    if(rxBuffer[0] == 0xAA && rxBuffer[1] == 0xAA && rxBuffer[2] == 0x02) {
      byte respCS = 0;
      for(int i = 0; i < 5; i++){
        respCS ^= rxBuffer[i];
      }
      if(respCS == rxBuffer[5]) {
        int rssiVal = (int)rxBuffer[3];
        int lqiVal  = (int)rxBuffer[4];
        Serial.print("Got response from Slave: RSSI=");
        Serial.print(rssiVal);
        Serial.print(", LQI=");
        Serial.println(lqiVal);
        
        float distance = approximateDistanceCalc(rssiVal);
        Serial.print("Approx distance: ");
        Serial.print(distance);
        Serial.println(" m");
        gotResponse = true;
        break;
      } else {
        Serial.println("Response XOR mismatch. Ignoring.");
      }
    } else {
      Serial.println("Unexpected response format from Slave.");
    }
  }
  if(millis() > nextPrint) {
    Serial.print("Countdown: ");
    Serial.println(countdown);
    countdown--;
    nextPrint += 1000;
  }
  if(countdown < 0) break;
  delay(50);
}

    
    if(!gotResponse)
      Serial.println("No valid response from Slave within 5 seconds.");
      
  } else if(digitalRead(BTN_PIN) == HIGH) {
    isPressed = false;
  }
  delay(100);
}