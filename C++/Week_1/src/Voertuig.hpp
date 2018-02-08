/*
 * Voertuig.hpp
 *
 *  Created on: 8 feb. 2018
 *      Author: arjon
 */

#ifndef VOERTUIG_HPP_
#define VOERTUIG_HPP_

#include <iostream>
using namespace std;

using namespace std;
class Voertuig {
	string jaartal;
	string merk;
	string soort;
	int jaar;

	public:
		Voertuig() {merk="leeg"; soort="leeg"; jaar=0; };
		Voertuig( string merk, string soort, int jaar);
		void leesData(char data[]); //lees de voertuigen uit het array
		void geefWeer(); //zet data op het scherm
		void naarJaar(); //gebruik c_string en je eigen functie zetJaarOm()
		int zetJaarOm(char jaar[6]);
};



#endif /* VOERTUIG_HPP_ */
