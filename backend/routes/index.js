const express = require("express");
const pool = require("../config");

router = express.Router();

router.get("/", async function (req, res, next) {
    try {
      let sql = 'SELECT * FROM accounts'
      const [rows, fields] = await pool.query(sql);
      return res.json(rows);
    } catch (err) {
      return res.status(500).json(err)
    }
  });


exports.router = router;
