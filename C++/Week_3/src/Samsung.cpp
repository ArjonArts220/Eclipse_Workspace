/*
 * Samsung.cpp
 *
 *  Created on: 26 feb. 2018
 *      Author: arjon
 */

#include <string>
#include "Samsung.hpp"
#include "Mobiel.hpp"
#include "Provider.hpp"

Samsung::Samsung(std::string e, std::string k){
	kleur = k;
	eigenaar = e;
}

std::string Samsung::getKleur(){
	return kleur;
}

void Samsung::setKleur(std::string k){
	kleur = k;
}

std::string Samsung::getEigenaar(){
	return eigenaar;
}

void Samsung::setEigenaar(std::string e){
	eigenaar = e;
}




