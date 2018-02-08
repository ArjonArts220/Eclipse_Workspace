/*
 * Voertuig.cpp
 *
 *  Created on: 8 feb. 2018
 *      Author: arjon
 */

#include "Voertuig.hpp";
#include <string.h>

Voertuig::Voertuig(string merk, string soort, int jaar) {
	this->merk = merk;
	this->soort = soort;
	this->jaar = jaar;
}

void Voertuig::geefWeer(){ //zet data op het scherm
	cout << soort << " merk: " << merk << " gekocht: "  << jaar << endl;
}

//"1990 motor bmw" ,"2000 auto Opel", "1984 vrachtwagen Daf"
void Voertuig::leesData(char data[]){
    string temp = data;
	jaartal.clear();
	this->jaartal = jaartal.append(data, 0, 4);
	soort.append(temp,5,11); //methode append van string gebruiken
	this->merk = temp.substr(temp.find_last_of(" ")+1, temp.length());
	//naarJaar();
}

void Voertuig::naarJaar() {
    char hetJaar[5];
//    strcpy(hetJaar, jaartal.c_str());
    jaar = zetJaarOm(hetJaar);
}

int Voertuig::zetJaarOm(char jaar[6]) {
    int aantalJaar = 0;
    for(int i=0; i<4; i++) {
        aantalJaar*=10;
        aantalJaar += jaar[i]-48;
    }
    if (aantalJaar > 1900 && aantalJaar < 2100) return aantalJaar;
    return 0;
}


