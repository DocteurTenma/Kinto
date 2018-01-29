const express = require('express')
const app = express()

app.use('/static', express.static(__dirname + '/build/static'));

app.get("/", (req, res) => {
    res.sendFile(__dirname + '/index.html');
})
app.get("/react", (req, res) => {
    res.sendFile(__dirname + '/build/index.html');
})

app.get("/startLight", (req, res) => {
    // Todo send order to the robot
    res.sendStatus(200);
})

app.listen(3000, () => {
    console.log("Kinto listening on port 3000!");
})
