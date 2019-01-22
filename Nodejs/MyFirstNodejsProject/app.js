var express = require('express');
var path = require('path');
var bodyParser = require('body-parser');

var indexRouter = require('./routes/index');

var app = express();

// view engine setup
app.set('views', path.join(__dirname, 'views'));
app.set('view engine', 'ejs');

// parse application/x-www-form-urlencoded
app.use(bodyParser.urlencoded({ extended: false }))

// parse application/json
app.use(bodyParser.json())//stopt alle request data (bv. form data) en stopt dat in json, hierdoor kan je hem gemakkelijk gebruiken.

app.use(express.static(path.join(__dirname, 'public')));

app.use('/login', indexRouter);

app.listen(3000);
