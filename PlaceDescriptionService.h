/*
 * PlaceDescriptionService.h
 *
 *  Created on: Dec 11, 2016
 *      Author: nico
 */

#ifndef PLACEDESCRIPTIONSERVICE_H_
#define PLACEDESCRIPTIONSERVICE_H_
#include "Http.h"
#include "string"
#include "Address.h"
#include "AddressExtractor.h"

class PlaceDescriptionService {
public:
	PlaceDescriptionService();
	PlaceDescriptionService(Http* http);

	virtual ~PlaceDescriptionService();

   std::string summaryDescription(const std::string& latitude, const std::string& longitude) const{
	   auto getRequestUrl = "lat=" + latitude + "&lon=" + longitude;
	   auto jsonResponse = http_->get(getRequestUrl);

	   AddressExtractor extractor;
	   auto address = extractor.addressFrom(jsonResponse);

	   return address.road + ", " + address.city + ", " + address.state + ", " + address.country;
   };


private:
   std::string createGetRequestUrl(
      const std::string& latitude, const std::string& longitude) const;
   std::string summaryDescription(const Address& address) const;

   Http* http_;

};


#endif /* PLACEDESCRIPTIONSERVICE_H_ */
