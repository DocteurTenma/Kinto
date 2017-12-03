const express = require('express')
const app = express()

app.get("/", (req, res) => {
    res.send("You are not pure");
})

app.get("/startLight", (req, res) => {
    // Todo send order to the robot
    res.sendStatus(200);
})

app.listen(3000, () => {
    console.log("Kinto listening on port 3000!");
})
