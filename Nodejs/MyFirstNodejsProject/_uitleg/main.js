 var mod = require('./module.js');
 console.log(mod.product(1,3));
 
 // Node.js heeft een aantal ingebouwde modules, genaamd core modules. Je hoeft hier geen ./ te grebuirken
 // 1. Read / write / delete files
  var fs = require('fs');
  
  var r = fs.readFileSync('readme.txt', 'utf8'); //read file sync is een synchrone function, dus eerst wordt deze functie helemaal afgemaakt voordat hij aan de volgende regel code begint.
  console.log(r);
  
  fs.readFile('readme.txt', 'utf8', function(err, data){ //dit is een assynchrone functie, de 'function(err, data)' wordt geroepen als hij klaar is met het lezen van de functie
	  console.log(data);
  });
  
  fs.writeFileSync('writeme.txt', r); //sync
  fs.writeFile('writeme.txt', r, function(err){
	if (err) throw err;
	console.log('Saved!');
  }); //async
  
  fs.unlink('writeme.txt', err => {if (err) console.log(err)});﻿ //delete file
  
  fs.mkdirSync('stuff'); //sync
  
  fs.rmdirSync('stuff'); //sync
  
  
  