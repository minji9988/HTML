const express = require("express");
const app = express();

app.get("/", (req, res) => {
    res.send("Here is the root.")
});

app.get("/login", (req, res) => {
    res.send("This is the login screen.")
});

app.listen(3000, function() {
    console.log("Start Server");
});


