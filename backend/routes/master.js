const express = require("express");
const pool = require("../config");
const bcrypt = require('bcrypt')
const { SerialPort } = require('serialport');
const { ReadlineParser } = require('@serialport/parser-readline');

const router = express.Router();

// เปิด serial port
const port = new SerialPort({
  path: 'COM3',
  baudRate: 115200,
});

const parser = port.pipe(new ReadlineParser({ delimiter: '\n' }));

// ตัวแปรสำหรับเก็บค่า Distance ล่าสุด
let latestDistance = null;

parser.on('data', (line) => {
  const data = line.trim();

  // เงื่อนไขที่จะแสดงเฉพาะบรรทัด Distance
  if (data.startsWith("📏 Distance :")) {
  const valueOnly = data.replace("📏 Distance :", "").trim().replace(" m", "");
  console.log(valueOnly);
}

  // ยังต้องอัปเดตค่า latestDistance ตามเดิม
  if (data.startsWith("📏 Distance :")) {
    const value = data.replace("📏 Distance :", "").trim().replace(" m", "");
    if (!isNaN(value)) {
      latestDistance = value;
    }
    else{
      Serial.printf("No distance data yet.");
    }
  }
});

//SlaveDistance
router.post('/slaveDistance', async (req, res, next) => {

    const conn = await pool.getConnection()
    await conn.beginTransaction()
    const slavename = req.body.slavename
    //console.log(slavename);
    
    try {
        const [slaves] = await conn.query(
            'SELECT * FROM slave WHERE slavename = ?', 
            [slavename]
        )
        slave = slaves[0]
        const distance = latestDistance
        // console.log(slave);
        const threshold = slave.threshold
        var message = "error"
        // console.log(distance);
        // console.log(threshold);
        if(distance >= threshold){
            message = "Your device is now out of range."
        }
        else{
            message = "Your device is now in range."
        }
        await conn.query(
            'UPDATE slave SET status = ?, timestamp = NOW() WHERE slavename = ? AND status != ?',
            [message, slavename, message]
        )
        
        const [slavedata] = await conn.query(
            'SELECT * FROM slave WHERE slavename = ?', 
            [slavename]
        )
        conn.commit()
        res.status(200).json({'slave': slavedata[0]})
        
    } catch (err) {
        conn.rollback()
        res.status(400).json(err.toString());
    } finally {
        conn.release()
    }
})

// API endpoint สำหรับดึงค่า Distance RSSI
router.get('/pulldistance', (req, res) => {
    console.log(latestDistance)
  if (latestDistance !== null) {
    res.json({ distance: latestDistance });
  } else {
    res.status(204).json({ message: "No distance data yet." });
  }
});

exports.router = router;