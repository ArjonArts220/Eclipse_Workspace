/*
 * Sms.hpp
 *
 *  Created on: 26 feb. 2018
 *      Author: arjon
 */

#ifndef SMS_HPP_
#define SMS_HPP_

#include <string>

class Sms{
	public:
		Sms();
		Sms(int sender, int receiver, std::string message);
		int getSender() const;
		int getReceiver() const;
		std::string getMessage() const;
	private:
		unsigned int m_nSender;
		unsigned int m_nReceiver;
		std::string m_sMessage;
	protected:
};




#endif /* SMS_HPP_ */

