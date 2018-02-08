//============================================================================
// Name        : Week_1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Mytimes.hpp"
#include "Voertuig.hpp"
#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
	char voertuigen[][80]= { "1990 motor bmw" ,
	                         "2000 auto Opel",
	                         "1984 vrachtwagen Daf"};
	Voertuig voertuig("Yahama","boot",2000);
	Voertuig vt;
	voertuig.geefWeer();
	vt.leesData(voertuigen[0]);
	vt.geefWeer();
	vt.leesData(voertuigen[1]);
	vt.geefWeer();
	vt.leesData(voertuigen[2]);
	vt.geefWeer();
	cin.get();
	return 0;
}
