/*
 * Mytimes.hpp
 *
 *  Created on: 8 feb. 2018
 *      Author: arjon
 */

#ifndef MYTIMES_HPP_
#define MYTIMES_HPP_

#include <iostream>
using namespace std;

class Mytimes {
    int h, m, s;
    public:
        void setTime(int hour, int min, int sec);
        void giveTime();
        int getHours();
        // int getMins();
        // int getSecs();
        void tick(); //1 second
        void add(int hour, int min, int sec);
        bool equals(Mytimes *t);
    private:
        void normalise(); // vb: 61 min 61 sec. ==> 1 h 2 min 1 sec
};



#endif /* MYTIMES_HPP_ */
