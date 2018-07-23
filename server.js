const express = require('express')
const app = express()
const PORT = process.env.PORT || 5000

const bodyParser = require('body-parser');
app.use(bodyParser.json());

// app.engine('html', require('ejs').renderFile);

app.get("/", (req, res) => {
    res.sendFile(__dirname + '/index.html');
})

app.get("/startLight", (req, res) => {
    // Todo send order to the robot
    res.sendStatus(200);
})

app.post("/lcd", (req, res) => {
    console.log(req.body.text);
    res.sendStatus(200);
})

app.listen(PORT, () => {
    console.log(`Kinto listening on port ${PORT}!`);
})
