/*
 * Student.cpp
 *
 *  Created on: 17 mrt. 2018
 *      Author: R
 */

#include "Student.hpp"
#include <iostream>
using namespace std;

Student :: Student(){
	cout << "Welke studie?: ";
	cin >> studie;
}
void Student :: print(){
	cout << naam << "studeert "<< studie << endl;
}


