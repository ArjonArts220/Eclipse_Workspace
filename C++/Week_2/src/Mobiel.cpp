/*
 * Mobiel.cpp
 *
 *  Created on: 16 feb. 2018
 *      Author: arjon
 */
#include "Mobiel.hpp"

Mobiel::Mobiel(Provider *provider, unsigned int number){
	m_pProvider = provider;
	m_nNumber = number;
}

void Mobiel::AddContact(std::string contact, int telnr){
	m_saContacts[contact] = telnr;
}

int Mobiel::getTelNr(std::string contact){
	return m_saContacts[contact];
}

unsigned int Mobiel::getNumber(){
	return m_nNumber;
}

void Mobiel::printSms(Sms *sms){
	cout << "Van: " << sms->getSender() << ", naar: " << sms->getReceiver() << ", bericht: " << sms->getMessage() << endl;
}

Sms* Mobiel::getSms(){
	return m_pSms;
}

Provider* Mobiel::getProvider(){
	return m_pProvider;
}

void Mobiel::writeSms(int nr, std::string message){
	m_pSms = new Sms(m_nNumber, nr, message);
	m_pProvider->writeSms(nr, m_pSms);
}

void Mobiel::writeSms(std::string contact, std::string message){
	m_pSms = new Sms(m_nNumber, m_saContacts[contact], message);
	m_pProvider->writeSms(m_saContacts[contact], m_pSms);
}



/*Mobiel();
		    Mobiel getMobiel();
		    void setMobiel(Mobiel m);
		unsigned int getNumber();
		Sms* getSms();
		Provider* getProvider();
		void AddContact(std::string contact, int telnr);
		int getTelNr(std::string contact);
		void printSms(Sms *sms);
		void writeSms(int nr, std::string message);
		void writeSms(std::string contact, std::string message);
*/
