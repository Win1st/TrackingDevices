#include <SPI.h>
#include <RadioLib.h>
#include <math.h>
#include <string.h>  // for memset()

//------------------ PIN DEFINITIONS -------------------
#define CS_PIN       10
#define GDO0_PIN     38
#define GDO2_PIN     39
#define SCK_PIN      36
#define MISO_PIN     37
#define MOSI_PIN     35
#define RST_PIN      -1

#define BTN1_PIN     15    // send 0x88 (Track)
#define BTN2_PIN     4     // send 0x80 (Buzzer)
#define LED_PIN      5     // Blink on valid RSSI response

//------------------ GLOBAL OBJECTS & VARIABLES ---------------------
SPIClass newSPI(HSPI);
CC1101 cc1101 = new Module(
  CS_PIN, GDO0_PIN, RST_PIN, GDO2_PIN,
  newSPI, SPISettings(2000000, MSBFIRST, SPI_MODE0)
);

float        dist        = 0.0;
byte         rxBuffer[4];     // header, cmd, RSSI, LQI
volatile bool receivedFlag  = false;

// Edge-detect flags for buttons
bool isPressed1 = false;
bool isPressed2 = false;

// FSM
enum class SysState : uint8_t { IDLE, WAIT };
SysState currentState = SysState::IDLE;

unsigned long startTime, nextPrint;
int           countdown;

// Forward-decl
void handlePacket();

//------------------ ISR-DRIVEN RECEIVE SETUP ---------------------
#if defined(ESP8266) || defined(ESP32)
ICACHE_RAM_ATTR
#endif
void setFlag() {
  receivedFlag = true;
}

// void initReceiveISR() {
//   cc1101.setPacketReceivedAction(setFlag);
//   cc1101.startReceive();
// }

//------------------ HELPERS ---------------------
float approximateDistanceCalc(int rssi) {
  const float RSSI_AT_1M   = -31.8;   // อ้างอิง RSSI ที่ระยะ 1 เมตร
  const float PATH_LOSS_N  = 2.0f;     // path-loss exponent

  float exponent = (RSSI_AT_1M - rssi) / (10.0f * PATH_LOSS_N);
  return pow(10.0f, exponent);

  // float exponent = (10.0f - (float)rssi - 40.0f) / 20.0f;
  // return pow(10.0f, exponent);
}

void blinkLED(unsigned long ms) {
  digitalWrite(LED_PIN, HIGH);
  delay(ms);
  digitalWrite(LED_PIN, LOW);
}

void sendCommand(uint8_t cmd) {
  byte payload[4] = { 0x01, cmd, 0x00, 0x00 };
  Serial.print("🚀 TRANSMIT CMD ");
  Serial.printf("%02X: ", cmd);
  for (auto b : payload) Serial.printf("%02X ", b);
  Serial.println();

  cc1101.transmit(payload, sizeof(payload));
  cc1101.finishTransmit();

  // re-arm RX
  cc1101.startReceive();
  Serial.println("✅ Packet sent. Waiting for response…");
}

void changeState(SysState next) {
  Serial.println(next == SysState::WAIT
    ? "🔄 Transition to WAIT"
    : "🔄 Transition to IDLE"
  );

  currentState = next;
  if (next == SysState::WAIT) {
    startTime  = millis();
    nextPrint  = startTime + 1000;
    countdown  = 5;
  }
}

//------------------ SETUP ---------------------
void setup() {
  Serial.begin(115200);

  pinMode(BTN1_PIN, INPUT_PULLUP);
  pinMode(BTN2_PIN, INPUT_PULLUP);
  pinMode(LED_PIN,   OUTPUT);

  newSPI.begin(SCK_PIN, MISO_PIN, MOSI_PIN, CS_PIN);
  if (cc1101.begin() != RADIOLIB_ERR_NONE) {
    Serial.println("❌ CC1101 init failed");
    while (true) delay(10);
  }
  Serial.println("✅ CC1101 initialized.");

  // CC1101 configuration
  cc1101.setFrequency(915);
  cc1101.setBitRate(0.6);
  cc1101.setOutputPower(12);
  cc1101.setSyncWord(0x2D, 0xD4);
  cc1101.setCrcFiltering(true);
  // cc1101.setOOK(true);
  cc1101.setNodeAddress(0x01, 1);

  // initReceiveISR();
  cc1101.setPacketReceivedAction(setFlag);
  cc1101.startReceive();

  Serial.println("🔁 Press BTN1 (Track) or BTN2 (Buzzer).");
}

//------------------ PACKET HANDLER ---------------------
void handlePacket() {
  receivedFlag = false;

  int16_t err = cc1101.readData(rxBuffer, sizeof(rxBuffer));
  if (err == RADIOLIB_ERR_NONE) {
    Serial.print("[CC1101] Received: ");
    for (int i = 0; i < 4; i++) {
      Serial.printf("%02X ", rxBuffer[i]);
    }
    Serial.println();

    if (rxBuffer[0] == 0x02 && rxBuffer[1] == 0x88) {
      Serial.println("✅ Valid header bytes received. Blinking LED...");
      blinkLED(2000);

      if (currentState == SysState::WAIT) {
        int8_t  rssi = (int8_t)rxBuffer[2];
        uint8_t lqi  = rxBuffer[3];
        Serial.printf("📶 RSSI=%d, LQI=%d\n", rssi, lqi);
        dist = approximateDistanceCalc(rssi);
        Serial.printf("📏 Distance :%.2f m\n", dist);

        // rxBuffer[0] = NULL;
        // rxBuffer[1] = NULL;
        // rxBuffer[2] = NULL;
        // rxBuffer[3] = NULL;

        // for (int i = 0; i < 4; i++) {
        //   Serial.printf("%02X ", rxBuffer[i]);
        // }
        // Serial.println();

        changeState(SysState::IDLE);
      }
    }
    else {
      Serial.println("⚠️ Unexpected header bytes");
    }
  }
  else {
    Serial.printf("⚠️ readData error: %d\n", err);
  }

  // **Clear out the rxBuffer so it holds zeros until the next packet**
  memset(rxBuffer, 0, sizeof(rxBuffer));

  // re-arm receive for next packet
  cc1101.startReceive();
}

//------------------ MAIN LOOP ---------------------
void loop() {
  // ——— 1) Always handle incoming packets immediately ———
  if (receivedFlag) {
    handlePacket();
  }

  // ——— 2) Read buttons at top of loop ———
  bool btn1 = (digitalRead(BTN1_PIN) == LOW);
  bool btn2 = (digitalRead(BTN2_PIN) == LOW);

  // Immediate, edge-detect sending
  if (btn1 && !isPressed1) {
    isPressed1 = true;
    sendCommand(0x88);
    changeState(SysState::WAIT);
  }
  else if (!btn1) {
    isPressed1 = false;
  }

  if (btn2 && !isPressed2) {
    isPressed2 = true;
    sendCommand(0x80);
    changeState(SysState::WAIT);
  }
  else if (!btn2) {
    isPressed2 = false;
  }

  // ——— 3) FSM for WAIT timeouts & countdown ———
  switch (currentState) {

    case SysState::IDLE:
      // keep listening
      Serial.printf("📏 Distance :%.2f m\n", dist);
      // Serial.printf("📏 Distance :0.04 m\n");
      cc1101.startReceive();
      break;

    case SysState::WAIT:
      // timeout?
      if (millis() - startTime >= 5000) {
        Serial.println("❌ No response (timeout)");
        changeState(SysState::IDLE);
      }
      // countdown update
      else if (millis() >= nextPrint) {
        Serial.printf("⏳ Countdown: %d\n", countdown);
        countdown--;
        nextPrint += 1000;
        Serial.printf("📏 Distance :%.2f m\n", dist);
        // Serial.printf("📏 Distance :0.04 m\n");
      }
      break;
  }

  delay(20);
}