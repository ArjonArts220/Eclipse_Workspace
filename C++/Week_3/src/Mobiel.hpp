/*
 * Mobiel.hpp
 *
 *  Created on: 26 feb. 2018
 *      Author: arjon
 */

#ifndef MOBIEL_HPP_
#define MOBIEL_HPP_

#include <string>
#include <map>
#include "Sms.hpp"
#include "Provider.hpp"

#include <iostream>
using namespace std;

class Provider;
class Mobiel{
	public:
		Mobiel();
		Mobiel(Provider *m_pProvider, unsigned int number);
		Mobiel(const Mobiel &m){
			m_nNumber = m.m_nNumber;
			m_pSms = m.m_pSms;
			m_pProvider = m.m_pProvider;
		};
		Mobiel(Mobiel &&m){
			m_nNumber = m.m_nNumber;
			m_pSms = m.m_pSms;
			m_pProvider = m.m_pProvider;

			m_nNumber = 0;
			m_pSms = nullptr;
			m_pProvider = nullptr;
		};
		Mobiel getMobiel();
		void setMobiel(Mobiel m);

		unsigned int getNumber();
		void setNumber(int);

		Sms* getSms();
		void setSms(Sms*);

		Provider* getProvider();
		void setProvider(Provider*);

		void AddContact(std::string contact, int telnr);
		int getTelNr(std::string contact);
		void printSms(Sms *sms);

		void writeSms(int nr, std::string message);
		void writeSms(std::string contact, std::string message);
		void writeWhatsappSms (std::string, std::string);
		void writeMessengerSms (std::string, std::string);


		unsigned int m_nNumber;
		Sms *m_pSms;
		Provider *m_pProvider;
		std::map<std::string, int> m_saContacts; //contact, telefoonnummer
	private:




	protected:
};
#endif /* MOBIEL_HPP_ */


/*Elke Mobiel–instantie kent zijn eigen provider en zijn eigen telefoonnummer. Ook bezit iedere
instantie het laatst verstuurde Sms bericht en een ‘lijst’ van de contacten.
Maak de klasse Mobiel. De klasse Mobiel heeft vier velden / attributen:
1. m_pProvider  een pointer naar zijn provider (nullptr indien niet gedefinieerd)
2. m_nNumber  het telefoonnummer horend bij de Mobiel (unsigned)
3. m_pSms  een pointer naar het laatst verstuurde Sms–bericht.
4. m_saContacts  een map met de contacten die de gebruiker van het mobiel heeft
Het type van dit veld is std::map<std::string,int>

1
Je kunt ook eerst alle header bestanden definiëren en dan de docent je broncode laten controleren.
Maak in ieder geval aparte header en implementatie bestanden.
2
Maak voor de klasse Mobiel:
 een default constructor
     een constructor waar de eerste twee velden gezet worden
     een copy en een move constructor.
     een copy en move assignment operator.
     getters voor elk van de eerste drie velden
 een methode om een contact toe te voegen
 een methode om het telefoonnummer van een contact op te vragen
 een methode om een Sms te tonen meteen als de mobiel ‘m ontvangt.
 twee methodes om een Sms te versturen:
1. op basis van telefoonnummer van de ontvanger
2. op basis van de naam van de ontvanger
Deze methode kan je nog niet afmaken omdat je daar de hulp van de klasse Provider voor nodig
hebt.
Laat je definities controleren door je docent.*/

