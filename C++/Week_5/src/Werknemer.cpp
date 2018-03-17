/*
 * Werknemer.cpp
 *
 *  Created on: 17 mrt. 2018
 *      Author: R
 */

#include "Werknemer.hpp"
#include <iostream>
using namespace std;

Werknemer :: Werknemer(){
	cout << "Voer afdeling in: ";
	cin >> afdeling;
}
void Werknemer :: print(){
	cout << naam << "werkt op afdeling "<< afdeling << endl;
}


