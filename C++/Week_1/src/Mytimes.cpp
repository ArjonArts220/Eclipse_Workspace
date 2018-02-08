/*
 * Mytimes.cpp
 *
 *  Created on: 8 feb. 2018
 *      Author: arjon
 */

#include "Mytimes.hpp"

void Mytimes::giveTime() {
    normalise();
    cout << h << " h " << m << " min " << s << " sec ";
}

void Mytimes::setTime(int hour, int min, int sec) {
    h = hour; m = min; s = sec;
}

int Mytimes:: getHours() {
    return h;
}

void Mytimes::tick() {
    s++;
}

void Mytimes::add(int hour, int min, int sec){
    h = h + hour;
    m = m + min;
    s = s + sec;
}

bool Mytimes::equals(Mytimes *t){
	if((*t).h == h && (*t).m == m && (*t).s == s){
		return true;
	}else{
		return false;
	}
}

void Mytimes::normalise(){
	m = m + int(s/60);
	h = h + int(m/60);
	m = m - (int(m/60) * 60);
	s = s - (int(s/60) * 60);
}



