//============================================================================
// Name        : Week_5.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include "Persoon.hpp"
#include "Werknemer.hpp"
#include "Student.hpp"

/*
 * 1.1 Welke constructoren werden aangeroepen?
 *		Constructor van hemzelf en van persoon
 * 1.2 Welke print() fucties werden aangeroepen?
 * 		Van persoon
 * 2.1 Welke functies print() worden nu aangeroepen?
 * 		Van de object zelf
 * 2.2 Wat is nu het verband tussen een virtuele functie en polymorfisme?
 * 		Met virtual geef je aan: als er dezelfde methode is die ergens anders gedefineerd is gebruik die dan.
 * */


int main() {
	Persoon *p, *q, *r;
	p = new Persoon;
	q = new Student;
	r = new Werknemer;
	p->print();
	q->print();
	r->print();
	return 0;
}
