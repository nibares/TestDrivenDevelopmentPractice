/*
 * PlaceDescriptionServiceBehavior.cpp
 *
 *  Created on: Dec 11, 2016
 *      Author: nico
 */

#include "catch.hpp"
#include "PlaceDescriptionService.h"
#include "string"

class APlaceDescriptionService {
  public:
		static const std::string validLatitude, validLongitude;
 };

const std::string APlaceDescriptionService::validLatitude("38.005");
const std::string APlaceDescriptionService::validLongitude("-104.44");

class HttpStub: public Http {
	void initialize() override {};
	std::string get(const std::string& url) const override{
		return R"({ "address": {
		"road":"Drury Ln",
		"city":"Fountain",
		"state":"CO",
		"country":"US" }})";
	}
};


SCENARIO_METHOD(APlaceDescriptionService,"Returns description for valid location", "[PlaceDescriptionService]" ){

	GIVEN("A call to the http service"){
		HttpStub httpStub;
		PlaceDescriptionService service{&httpStub};

		WHEN("We have a valid location"){

			auto description = service.summaryDescription(validLatitude, validLongitude);

			THEN("The description is the correct one to the location"){
				REQUIRE(description == "Drury Ln, Fountain, CO, US");
			}
		}
	}
}


