/*
 * LFOSawTest.cpp
 *
 *  Created on: 12 Sep 2016
 *      Author: leo
 */

#include "catch.hpp"
#include "FixedValue.h"
#include "LFOSaw.h"

TEST_CASE( "LFOSaw returns saw values", "[LFOSaw]" ) {

	GIVEN( "A new LFOSaw object" ) {
		FixedValue<5> wavelength;
		FixedValue<10> amplitude;
		FixedValue<1> minimum;
		LFOSaw<Value, Value> lfo(wavelength, amplitude, minimum);

		WHEN( "get is called immediately" ) {
			auto got = lfo.get();

			THEN( "the minimum value is returned" ) {
				REQUIRE( got == minimum.get() );
			}
			THEN( "repeated calls to get all return the same value" ) {
				REQUIRE( lfo.get() == got );
				REQUIRE( lfo.get() == got );
				REQUIRE( lfo.get() == got );
			}
			WHEN( "next is called" ) {
				auto second_val = lfo.next();
				THEN( "a new, greater, value is returned" ) {
					REQUIRE( second_val > got );
				}
				THEN( "get returns the new value, too" ) {
					REQUIRE( lfo.get() == second_val);
					REQUIRE( lfo.get() == second_val);
				}

				WHEN( "next is called one more time" ) {
					THEN( "the value increases again" ) {
						REQUIRE( lfo.next() > second_val );
					}
				}

				WHEN( "next is called another wavelength - 1 times" ) {
					for (int i = 0; i < wavelength.get() - 1; ++i) {
						lfo.next();
					}

					THEN( "the value cycles back to minimum" ) {
						REQUIRE( lfo.get() == minimum.get() );
					}
				}
			}
		}
	}
}


