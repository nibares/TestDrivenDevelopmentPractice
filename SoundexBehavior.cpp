//This file describes the Soundex Behavior...

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "Soundex.h"

SCENARIO("Retain first letter of a one letter word", "[SoundexEncoding]" ) {

	Soundex soundex;
	std::string encoded;

	GIVEN("A one letter word."){
		WHEN("Soundex encodes the word."){
			encoded = soundex.encode("A");

			THEN("We received the same one letter word and the rest zeroes."){
					REQUIRE(encoded == "A000");
			}
		}
	} //EndGiven
} //End Scenario


SCENARIO( "Pad with zeroes when until have 3 digits after letter", "[SoundexEncoding]" ) {
	Soundex soundex;
	std::string encoded;

	GIVEN("A one letter word."){
		WHEN("Soundex encodes the word."){
			encoded = soundex.encode("I");
			THEN("We received the same one letter word and the rest zeroes."){
					REQUIRE(encoded == "I000");
			}
		}
	} //EndGiven
} //End Scenario

SCENARIO( "Replace consonants with appropiate digits", "[SoundexEncoding]" ) {
	Soundex soundex;
	std::string encoded;

	GIVEN("A word with two letters"){
		WHEN("Soundex encodes the word."){
			encoded = soundex.encode("Ax");
			THEN("It replaces with the correct digits."){
					REQUIRE(encoded == "A200");
			}
		}
	} //EndGiven
} //End Scenario

SCENARIO( "Ignore not recognized letters", "[SoundexEncoding]" ) {
	Soundex soundex;
	std::string encoded;

	GIVEN("A word with not recognized characters"){
		WHEN("Soundex encodes the word."){
			encoded = soundex.encode("A#");
			THEN("it ignores the unrecognized character and encodes the rest."){
					REQUIRE(encoded == "A000");
			}
		}
	} //EndGiven
} //End Scenario

SCENARIO( "Encode multiple characters at the same time", "[SoundexEncoding]" ) {
	Soundex soundex;
	std::string encoded;

	GIVEN("A word with multiple characters"){
		WHEN("Soundex encodes the word."){
			encoded = soundex.encode("Acdl");
			THEN("it encodes each character accordingly."){
					REQUIRE(encoded == "A234");
			}
		}
	} //EndGiven
} //End Scenario

SCENARIO( "Encode any quantity of letters but show only 4", "[SoundexEncoding]" ) {
	Soundex soundex;
	std::string encoded;

	GIVEN("A word with more than four characters"){
		WHEN("Soundex encodes the word."){
			encoded = soundex.encode("Dcdls");
			THEN("it encodes each character accordingly."){
					REQUIRE(encoded.length() == 4);
			}
		}
	} //EndGiven
} //End Scenario

SCENARIO( "Ignore vowel like letters", "[SoundexEncoding]" ) {
	Soundex soundex;
	std::string encoded;

	GIVEN("A word with vowels and w,h and y"){
		WHEN("Soundex encodes the word."){
			encoded = soundex.encode("BaAeEiIoOuUhHyYcdl");
			THEN("it encodes each character and ignores vowel like letters."){
					REQUIRE(encoded == "B234");
			}
		}
	} //EndGiven
} //End Scenario

SCENARIO( "Combine duplicates encodings", "[SoundexEncoding]" ) {
	Soundex soundex;
	std::string encoded;

	GIVEN("A word with Abfcgdt b and f both encode to 1, c and g both encode to 2, and d and both encode to 3"){
		WHEN("Soundex encodes the word."){
			encoded = soundex.encode("Abfcgdt");
			THEN("it encodes each character ignoring duplicates."){
					REQUIRE(encoded == "A123");
			}
		}
	} //EndGiven
} //End Scenario

SCENARIO( "Upper Case first letter", "[SoundexEncoding]" ) {
	Soundex soundex;
	std::string encoded;

	GIVEN("A word that starts in lower case"){
		WHEN("Soundex encodes the word."){
			encoded = soundex.encode("abfcgdt");
			THEN("it encodes having first letter as Upper case."){
					REQUIRE(encoded == "A123");
			}
		}
	} //EndGiven
} //End Scenario

SCENARIO( "Validate consonants casing", "[SoundexEncoding]" ) {
	Soundex soundex;
	std::string encodedUpper, encodedLower;

	GIVEN("A word that have upper case (ie. BCDL)"){
		WHEN("Soundex encodes the word."){
			encodedUpper = soundex.encode("BCDL");
			encodedLower = soundex.encode("bcdl");

			THEN("and it matches the code of the same word with lower case consonants (ie. bcdl)."){
					REQUIRE(encodedUpper == encodedLower);
			}
		}
	} //EndGiven
} //End Scenario

SCENARIO( "Combines Duplicate Codes When 2nd Letter Duplicates 1st", "[SoundexEncoding]" ) {
	Soundex soundex;
	std::string encoded;

	GIVEN("A word like Bbcd)"){
		WHEN("Soundex encodes the word."){
			encoded = soundex.encode("Bbcd");

			THEN("and combines duplicate codes."){
					REQUIRE(encoded == "B230");
			}
		}
	} //EndGiven
} //End Scenario

SCENARIO( "Does not Combines Duplicate Codes When Separated by Vowels", "[SoundexEncoding]" ) {
	Soundex soundex;
	std::string encoded;

	GIVEN("A word like Jbob)"){
		WHEN("Soundex encodes the word."){
			encoded = soundex.encode("Jbob");

			THEN("and combines duplicate codes."){
					REQUIRE(encoded == "J110");
			}
		}
	} //EndGiven
} //End Scenario

SCENARIO( "Prueba con Mazzali", "[SoundexEncoding]" ) {
	Soundex soundex;
	std::string encoded;

	GIVEN("A word like Jbob)"){
		WHEN("Soundex encodes the word."){
			encoded = soundex.encode("Mazzali");

			THEN("Y muestra el codigo."){
					REQUIRE(encoded == "J110");
			}
		}
	} //EndGiven
} //End Scenario
