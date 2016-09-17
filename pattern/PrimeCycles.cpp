/*
 * PrimeSines.cpp
 *
 *  Created on: 16 Sep 2016
 *      Author: leo
 */

#include "PrimeCycles.h"
#include <cmath>

template <int period>
float sinusoid(int i) {
	return sin(2 * M_PI * (i % period) / period);
}

void PrimeCycles::updateFrame(CHSV* frame) {
	++frame_count;
	float saturation_sin = ::sinusoid<2791>(frame_count);
	float saturation = 255 - 210 * saturation_sin * saturation_sin;
	float base_colour = ::sinusoid<20071>(frame_count);
	for (int i = 0; i < Pattern::num_leds; ++i) {
		float value_sin = (  ::sinusoid<587>(frame_count + i)
				            + ::sinusoid<593>(frame_count + i)) / 2
				         * (  ::sinusoid<331>(frame_count + Pattern::num_leds - i)
						    + ::sinusoid<349>(frame_count + Pattern::num_leds - i))
				         / 2;
		frame[i] = CHSV(
				255 * ( ( ::sinusoid<131>(frame_count + i)
			            + ::sinusoid<137>(frame_count + i)) /2
				      * ( ::sinusoid<443>(frame_count + Pattern::num_leds - i)
					    + ::sinusoid<449>(frame_count + Pattern::num_leds - i)) / 2
						+ base_colour),
				saturation,
				(128 + 127 * value_sin) / (1 + (255 - saturation) / 768)
				);
	}
}

// Abstract out sinusoid calculation (inline template function?)
// Make values sums of sinusoids with coprime frequencies.
//  Use similar primes to get interesting beat frequencies (eg: 337 & 347, 131 & 139, 89 & 97 & 101 or 103)
