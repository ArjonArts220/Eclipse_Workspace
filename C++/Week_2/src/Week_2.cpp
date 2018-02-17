//============================================================================
// Name        : Week_2.cpp
// Author      : Arjon Arts
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Mobiel.hpp"
#include "Sms.hpp"
#include "Provider.hpp"

#include <iostream>
using namespace std;

int main() {
	Provider provider;

	unsigned int mb1nm = 1111;
	Mobiel mb1(&provider, mb1nm);

	unsigned int mb2nm = 2222;
	Mobiel mb2(&provider, mb2nm);

	unsigned int mb3nm = 3333;
	Mobiel mb3(&provider, mb3nm);

	mb1.AddContact("Piet", mb2.getNumber());
	mb1.AddContact("Klaas", mb3.getNumber());

	mb2.AddContact("Henk", mb1.getNumber());
	mb2.AddContact("Klaas", mb3.getNumber());

	mb3.AddContact("Henk", mb1.getNumber());
	mb3.AddContact("Piet", mb2.getNumber());

	provider.addMobile(&mb1);
	provider.addMobile(&mb2);
	provider.addMobile(&mb3);

	mb2.writeSms(3333, "T-10 ... 9 ... 8 ...");
	mb1.writeSms(2222, "2 ... 1 ... Rakat is launched");

	mb3.writeSms(mb3.getTelNr("Piet"), "Hallo Piet");
	return 0;
}
