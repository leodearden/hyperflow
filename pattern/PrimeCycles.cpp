/*
 * PrimeSines.cpp
 *
 *  Created on: 16 Sep 2016
 *      Author: leo
 */

#include "PrimeCycles.h"
#include <cmath>

template <int period>
double sinusoid(int i) {
	return sin(2 * M_PI * (i % period) / period);
}

void PrimeCycles::updateFrame(CHSV* frame) {
	++frame_count;
	for (int i = 0; i < Pattern::num_leds; ++i) {
		frame[i] = CHSV(
				255 * ( ( ::sinusoid<131>(frame_count + i)
			            + ::sinusoid<137>(frame_count + i)) /2
				      * ( ::sinusoid<443>(frame_count + Pattern::num_leds - i)
					    + ::sinusoid<449>(frame_count + Pattern::num_leds - i)) / 2
					  + ::sinusoid<20071>(frame_count)),
				((((i/8) % 2) ^ (frame_count/8) % 2) == 0) ? 255 : 128 + 127 * ::sinusoid<2791>(frame_count),
				128 + 127 * ( ( ::sinusoid<971>(frame_count + i)
						      + ::sinusoid<1009>(frame_count + i)) /2
				      * ( ::sinusoid<67>(frame_count + Pattern::num_leds - i)
					    + ::sinusoid<71>(frame_count + Pattern::num_leds - i)) / 2 )
				);
	}
}

// Abstract out sinusoid calculation (inline template function?)
// Make values sums of sinusoids with coprime frequencies.
//  Use similar primes to get interesting beat frequencies (eg: 337 & 347, 131 & 139, 89 & 97 & 101 or 103)
