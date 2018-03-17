/*
 * Werknemer.hpp
 *
 *  Created on: 17 mrt. 2018
 *      Author: R
 */

#ifndef WERKNEMER_HPP_
#define WERKNEMER_HPP_

#include "Persoon.hpp"

class Werknemer : public Persoon{
	protected:
		char afdeling[20];
	public:
		Werknemer();
		void print();
};



#endif /* WERKNEMER_HPP_ */
