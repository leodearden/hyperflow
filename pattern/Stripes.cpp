/*
 * Stripes.cpp
 *
 *  Created on: 22 Aug 2016
 *      Author: leo
 */

#include "Stripes.h"

void Stripes::updateFrame(CHSV* frame) {
	CHSV value(0xff, 0x0, ((frame_count / width.get()) % 2) ? 0xff : 0);
	for(int i = 0; i < Pattern::num_leds; ++i) {
		frame[i] = value;
	}
	++frame_count;
}

Stripes::Stripes(Value& width_) :
	frame_count(0),
	width(width_)
{}
