/*
 * Pattern.h
 *
 *  Created on: 20 Aug 2016
 *      Author: leo
 */

#ifndef PATTERN_H_
#define PATTERN_H_

#include "FastLED.h"

class Pattern {
public:
	Pattern() {}
	virtual ~Pattern();
	virtual void updateFrame(CHSV* frame) = 0;

	static const int num_leds = 144;
};

#endif /* PATTERN_H_ */
