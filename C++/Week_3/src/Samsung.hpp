/*
 * Samsung.hpp
 *
 *  Created on: 26 feb. 2018
 *      Author: arjon
 */

#ifndef SAMSUNG_HPP_
#define SAMSUNG_HPP_

#include "Mobiel.hpp"

class Samsung{
	public:
		Samsung(std::string, std::string);
		std::string getKleur();
		void setKleur(std::string k);

		std::string getEigenaar();
		void setEigenaar(std::string );

	private:
		std::string kleur;
		std::string eigenaar;
};



#endif /* SAMSUNG_HPP_ */
