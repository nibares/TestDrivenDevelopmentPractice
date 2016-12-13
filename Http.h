/*
 * Http.h
 *
 *  Created on: Dec 11, 2016
 *      Author: nico
 */

#ifndef HTTP_H_
#define HTTP_H_

#include "string"

class Http{

public:
	virtual void initialize() = 0;
	virtual std::string get(const std::string& url) const = 0;
	virtual ~Http() {}
};


#endif /* HTTP_H_ */
