const express = require("express");
const pool = require("../config");
const Joi = require('joi')
const bcrypt = require('bcrypt')
const upload = require("../multer");

router = express.Router();

const passwordValidator = (value) => {
    if (value.length < 8) {
        throw new Joi.ValidationError('Password must contain at least 8 characters')
    }
    if (!(value.match(/[a-z]/) && value.match(/[A-Z]/) && value.match(/[0-9]/))) {
        throw new Joi.ValidationError('Password must be harder')
    }
    return value
}

const usernameValidator = async (value) => {
    const [rows, _] = await pool.query(
        "SELECT username FROM accounts WHERE username = ?",
        [value]
    )
    if (rows.length > 0) {
        const message = 'This username is already exists'
        throw new Joi.ValidationError(message, { message })
    }
    return value
}


//SignUP
router.post('/user/signup', async (req, res, next) => {
    const signupSchema = Joi.object({
        username: Joi.string().required().min(5).max(20).external(usernameValidator),
        password: Joi.string().required().custom(passwordValidator),
        confirmPassword: Joi.ref('password'),
        firstname: Joi.string().max(100).required(),
        lastname: Joi.string().max(100).required(),
        email: Joi.string().email().required(),
        phone: Joi.string().required().pattern(/0[0-9]{9}/),
    })
    try {
        await signupSchema.validateAsync(req.body, { abortEarly: false })
    } catch (err) {
        return res.status(400).send(err)
    }
    const conn = await pool.getConnection()
    await conn.beginTransaction()
    const username = req.body.username
    const password = await bcrypt.hash(req.body.password, 5)
    const firstname = req.body.firstname
    const lastname = req.body.lastname
    const email = req.body.email
    const phone = req.body.phone
    try {
        await conn.query(
            'INSERT INTO accounts(username, password, firstname, lastname, email, phone, date) VALUES (?, ?, ?, ?, ?, ?, current_timestamp())',
            [username, password, firstname, lastname, email, phone]
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


//SignIN
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
        if (!account) {    
            throw new Error('Incorrect username or password')
        }
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