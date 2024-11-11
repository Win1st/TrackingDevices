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

  router.get("/userSlave", async function (req, res, next) {
    try {
      const search = req.query.search || ''
      let sql = 'SELECT * FROM connect JOIN slave ON connect.slave_id = slave.id'
      
      let cond = []

      if (search.length > 0) {
        sql += ' WHERE connect.username = ?'
        cond = [search]
      }
      const [rows, fields] = await pool.query(sql, cond);
      
      return res.json(rows);
    } catch (err) {
      return res.status(500).json(err)
    }
  });

exports.router = router;
