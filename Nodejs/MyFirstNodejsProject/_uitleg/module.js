 /* Dit is een module, hier stop je een aantal functies in die bij elkeaar horen, bijvoorbeeld matmathical functions
  * Als je deze functies in een andere file wilt gebruiken moet je deze functie exporteren, dit kan op 3 manieren zoals hieronder beschreven is.
  */
  
  
//Manier 1  
 var add = function(a, b){
	return a + b; 
 };
 module.exports.add = add;
 
 //manier 2
 module.exports.divide = function(a, b){
	 return a/b;
 };
 
 var product = function(a, b){
	return a * b; 
 };
 
module.exports = {
	product: product
	//, divide: divide,
	//  add: add
};