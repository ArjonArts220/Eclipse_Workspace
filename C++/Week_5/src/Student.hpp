/*
 * Student.hpp
 *
 *  Created on: 17 mrt. 2018
 *      Author: R
 */

#ifndef STUDENT_HPP_
#define STUDENT_HPP_

#include "Persoon.hpp"
#include <iostream>
using namespace std;


class Student : public Persoon{
	protected:
		char studie[30];
	public:
		Student();
		void print();
};




#endif /* STUDENT_HPP_ */
