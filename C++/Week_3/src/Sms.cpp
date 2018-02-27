/*
 * Sms.cpp
 *
 *  Created on: 26 feb. 2018
 *      Author: arjon
 */

#include <string>
#include "Sms.hpp";




Sms::Sms(int sender, int receiver, std::string message){
	m_nSender = sender;
	m_nReceiver = receiver;
	m_sMessage = message;
}

int Sms::getSender() const{
	return m_nSender;
}

int Sms::getReceiver() const{
	return m_nReceiver;
}

std::string Sms::getMessage() const{
	return m_sMessage;
}





