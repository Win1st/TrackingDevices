const express = require("express");
const pool = require("../config");

router = express.Router();

router.get("/user", async function (req, res, next) {
    try {
      let sql = 'SELECT * FROM accounts'
      
      const [rows, fields] = await pool.query(sql);
      return res.json(rows);
    } catch (err) {
      return res.status(500).json(err)
    }
  });
  
router.get("/slave", async function (req, res, next) {
    try {
      let sql = 'SELECT * FROM slave'
      
      const [rows, fields] = await pool.query(sql);
      return res.json(rows);
    } catch (err) {
      return res.status(500).json(err)
    }
  });

exports.router = router;
