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

template <int period>
class FastSin {
public:
	FastSin() {
		for (int i = 0; i < period; ++i) {
			lut[i] = sin(2 * M_PI * (i % period) / period);
		}
	}
	float operator()(int i) {return lut[i%period];}
private:
	float lut[period];
};

void PrimeCycles::updateFrame(CHSV* frame) {
	++frame_count;
	float saturation_sin = ::sinusoid<2791>(frame_count);
	float saturation = 255 - 210 * saturation_sin * saturation_sin;
	float base_colour = ::sinusoid<20071>(frame_count);
	static FastSin<587> fs587;
	static FastSin<593> fs593;
	static FastSin<331> fs331;
	static FastSin<349> fs349;
	static FastSin<131> fs131;
	static FastSin<137> fs137;
	static FastSin<443> fs443;
	static FastSin<449> fs449;
	for (int i = 0; i < Pattern::num_leds; ++i) {
		float value_sin = (  fs587(frame_count + i)
				            + fs593(frame_count + i)) / 2
				         * (  fs331(frame_count + Pattern::num_leds - i)
						    + fs349(frame_count + Pattern::num_leds - i))
				         / 2;
		frame[i] = CHSV(
				255 * ( ( fs131(frame_count + i)
			            + fs137(frame_count + i)) /2
				      * ( fs443(frame_count + Pattern::num_leds - i)
					    + fs449(frame_count + Pattern::num_leds - i)) / 2
						+ base_colour),
				saturation,
				(128 + 127 * value_sin) / (1 + (255 - saturation) / 768)
				);
	}
}

// Abstract out sinusoid calculation (inline template function?)
// Make values sums of sinusoids with coprime frequencies.
//  Use similar primes to get interesting beat frequencies (eg: 337 & 347, 131 & 139, 89 & 97 & 101 or 103)
