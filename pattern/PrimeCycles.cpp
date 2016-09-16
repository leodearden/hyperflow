/*
 * PrimeSines.cpp
 *
 *  Created on: 16 Sep 2016
 *      Author: leo
 */

#include "PrimeCycles.h"

void PrimeCycles::updateFrame(CHSV* frame) {
	++frame_count;
	for (int i = 0; i < Pattern::num_leds; ++i) {
		frame[i] = CHSV(((frame_count + i) % h_period) * 255 / h_period,
				255,
				((frame_count + Pattern::num_leds - i) % v_period) * 255 / v_period);
	}
}
