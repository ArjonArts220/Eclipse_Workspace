/*
 * Persoon.cpp
 *
 *  Created on: 17 mrt. 2018
 *      Author: R
 */

#include "Persoon.hpp"
#include <iostream>
using namespace std;

Persoon :: Persoon(){
	cout << "Voer naam in: ";
	cin >> naam;
}
void Persoon :: print(){
	cout << "Deze persoon heet: "<< naam << endl;
}



