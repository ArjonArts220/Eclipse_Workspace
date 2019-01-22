//express is een handigere manier om een server te maken

var express = require('express'); 
 
var app = express(); 
 
app.get('/', function(req, res){//als iemand een HTTP-GET-request maakt
	//je hoeft geen headers toe te voegen omdat hij dit automatisch doet door te kijken wat je verzend.
	res.send('this is a homepage');
});

//bv bij facebook, als je zegt facebook.com/profile/arjonarts dan vraag je alle gevens van arjonarts op. Je moet dan voor alle namen een app.get() maken, dit is onhandig.
//een makkelijkere manier om de naam variable te houden is door ':name' te gebruiken
app.get('/profile/:name', function(req, res){//als iemand een HTTP-GET-request maakt
	res.send('You requested a profile with the id: ' + req.params.name);
});

//query strings -> /profiles?name=arjonarts&age=24
app.get('/profile', function(req, res){//als iemand een HTTP-GET-request maakt
	res.send(req.query); //req.query is json
});
  
//stuur een html file terug 
app.get('/askhtml', function(req, res){//als iemand een HTTP-GET-request maakt
	res.sendFile(__dirname + '/server_page_to_send.html');
});

//een makkelijke manier om data van een form te lezen is door de module body-parser. Dus jeh hebt een form met een input name 'username'.
//en die wilt je lezen om daar uiteinlijk iets mee te doen. 
//1. npm install body-parser 
var bodyParser = require('body-parser');
var urlencodedParser = bodyParser.urlencoded({ extended: false })

app.post('/post', urlencodedParser, function(req, res){//als iemand een HTTP-GET-request maakt
  if (!req.body) return res.sendStatus(400);
  res.send('welcome, ' + req.body.username);
});

app.listen(3000);
 
  