//Maak een eigen server aan
 
var http = require('http');
var fs = require('fs');
 
 
var server = http.createServer(function(request, response){ //deze functie wordt aangeroepen als iemand een request maakt aan de server. In 'request' staat alle informatie van het binnenkomende bericht en in response alle informatie die jij naar de wlient wilt sturen.
	//Elke response heeft een header, dit is extra informatie van het bericht. De eerste parameter is de status (bv 200 -> OK, 404 -> Error not found)
	//1. send plane text
 	//response.writeHead(200, {'Content-Type': 'text/plain'}); 	 
	//response.end('this is the real message');
	 
	//2. send html page
 	//response.writeHead(200, {'Content-Type': 'text/html'}); 	 
	//var r = fs.readFileSync('server_page_to_send.html', 'utf8'); //liever async maar word anders onduidlijk
	//console.log(r);
 	//response.write(r);
	//response.end();

	//3. send json
 	response.writeHead(200, {'Content-Type': 'application/json'}); 	 
	var json = {
		name: 'arjon',
		age : 20,
		job : 'unimployed'
	};
 	response.write(JSON.stringify(json));
	response.end();	
});
 
server.listen(3000, '127.0.0.1'); //nu luister de server of er een request binnenkomt op poort 3000
console.log('listening to port 3000');