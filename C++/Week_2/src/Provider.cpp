/*
 * Provider.cpp
 *
 *  Created on: 16 feb. 2018
 *      Author: arjon
 */

#include "Provider.hpp"

Provider::Provider(){
	cout << "provider constructor" << endl;
}


void Provider::addMobile(Mobiel *m){
	m_pMobiel.push_back(m);
}

Mobiel* Provider::getMobiel(int telnr){
	for(unsigned int i = 0 ; i < m_pMobiel.size() ; i++){
		if(m_pMobiel[i]->getNumber() == (unsigned int)telnr){
			return m_pMobiel[i];
		}
	}
	return 0;
}

void Provider::writeSms(int nr, Sms *sms){
	for(unsigned int i = 0 ; i < m_pMobiel.size() ; i++){
		if(m_pMobiel[i]->getNumber() == (unsigned int)nr){
			m_pMobiel[i]->printSms(sms);
		}
	}
}


