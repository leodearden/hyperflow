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
				128 + 127 * ::sinusoid<131>(frame_count + i)
				          * ::sinusoid<89>(frame_count + Pattern::num_leds - i),
				255,
				255);
//				((frame_count + Pattern::num_leds - i) % v_period) * 255 / v_period);
	}
}

// Abstract out sinusoid calculation (inline template function?)
// Make values sums of sinusoids with coprime frequencies.
//  Use similar primes to get interesting beat frequencies (eg: 337 & 347, 131 & 139, 89 & 97 & 101 or 103)
