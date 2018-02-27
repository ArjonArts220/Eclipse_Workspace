/*
 * Provider.hpp
 *
 *  Created on: 26 feb. 2018
 *      Author: arjon
 */

#ifndef PROVIDER_HPP_
#define PROVIDER_HPP_

#include <vector>
#include "Mobiel.hpp"
#include "Sms.hpp"

#include <iostream>
using namespace std;

class Mobiel;
class Provider {
public:
		Provider();
		Provider(const Provider &m){
			m_pMobiel = m.m_pMobiel;
		};
		Provider(Provider &&m){
			m_pMobiel = m.m_pMobiel;
			m_pMobiel.clear();
		};

		void addMobile(Mobiel *m);
		Mobiel* getMobiel(int telnr);
		void writeSms(int nr, Sms *sms); //check in vector of tel tegenkomt dan stuur sms
	private:
		std::vector<Mobiel*> m_pMobiel;
	protected:

};



#endif /* PROVIDER_HPP_ */

/*Een provider bezit de Mobiel–instanties:
Mobiel *m_pMobiel
Dit is een dynamische array die je moet kunnen uitbreiden. Gebruik hiervoor GEEN c–constructs.
Maak voor de klasse Provider:
Een default constructor.
    Een copy en een move constructor.
    Een copy en move assignment operator.
Een methode om een Mobiel–instantie toe te voegen.
Een methode om een pointer van een Mobiel te ontvangen op basis van het telefoonnummer.
Een methode om een Sms te versturen.*/

