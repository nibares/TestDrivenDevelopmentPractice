/*
 * Address.h
 *
 *  Created on: Dec 11, 2016
 *      Author: nico
 */

#ifndef ADDRESS_H_
#define ADDRESS_H_

#include "String.h"

class Address{

public:
	std::string road, city, state, country;

	Address();
	~Address();
};


#endif /* ADDRESS_H_ */
