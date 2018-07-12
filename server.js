const express = require('express')
const app = express()

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

app.listen(3000, () => {
    console.log("Kinto listening on port 3000!");
})
