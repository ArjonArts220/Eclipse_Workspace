/*
 * Burrito.cpp
 *
 *  Created on: 8 feb. 2018
 *      Author: arjon
 */

#include <iostream>
#include "Burrito.hpp"


using namespace std;
Burrito::Burrito(){ //constructor, deze word aangeroepen zodra je het object maakt van Burrito
    cout << "I am a constructor" << endl;
}

Burrito::~Burrito(){ //deconstructor, als het object word destoryd (bv einde programma), dan word de deconstructor aangeroepen. Let op: een deconstructor heeft nooit
                     //een returnvalue en parameters.
    cout << "I am a deconstructor" << endl;
}

void Burrito::printCrap(){ //:: betekent dat printCrap() bij Burrito-class hoort
    cout << "crap" << endl;
}

