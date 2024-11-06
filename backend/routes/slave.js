const express = require("express");
const pool = require("../config");
const Joi = require('joi')
const bcrypt = require('bcrypt')
const upload = require("../multer");

router = express.Router();

//Slave1
router.post('/slaveAdding', async (req, res, next) => {

    const conn = await pool.getConnection()
    await conn.beginTransaction()
    const slavename = req.body.slavename
    const mastername = req.body.mastername
    const username = req.body.username
    const password = req.body.password
    
    try {
        const [accounts] = await conn.query(
            'SELECT * FROM accounts WHERE username = ?', 
            [username]
        )
        const account = accounts[0]
        
        // Check if password is correct
        if (!(await bcrypt.compare(password, account.password))) {
            throw new Error('Incorrect username or password')
        }

        await conn.query(
            'INSERT INTO slave(slavename, mastername) VALUES (?, ?)',
            [slavename, mastername]
        )   
        conn.commit()
        res.status(201).send()
    } catch (err) {
        conn.rollback()
        res.status(400).json(err.toString());
    } finally {
        conn.release()
    }

})

//Slave2
router.post('/slaveSetting', async (req, res, next) => {

    const conn = await pool.getConnection()
    await conn.beginTransaction()
    const slavename = req.body.slavename
    const threshold = req.body.threshold
    const notify = req.body.notify
    
    try {
        await conn.query(
            'UPDATE slave SET threshold = ?, notify = ? WHERE slavename = ?',
            [threshold, notify, slavename]
        )
        conn.commit()
        res.status(201).send()
    } catch (err) {
        conn.rollback()
        res.status(400).json(err.toString());
    } finally {
        conn.release()
    }
})

//LogIn
router.post('/user/login', async (req, res, next) => {
    const loginSchema = Joi.object({
        username: Joi.string().required(),
        password: Joi.string().required()
    })
    try {
        await loginSchema.validateAsync(req.body, { abortEarly: false })
    } catch (err) {
        return res.status(400).send(err)
    }
    const username = req.body.username
    const password = req.body.password

    const conn = await pool.getConnection()
    await conn.beginTransaction()

    try {
        // Check if username is correct
        const [accounts] = await conn.query(
            'SELECT * FROM accounts WHERE username=?', 
            [username]
        )
        const account = accounts[0]
        
        // Check if password is correct
        if (!(await bcrypt.compare(password, account.password))) {
            throw new Error('Incorrect username or password')
        }
        conn.commit()
        res.status(200).json({'account': account})
    } catch (error) {
        conn.rollback()
        res.status(403).json(error.toString())
    } finally {
        conn.release()
    }
})

exports.router = router