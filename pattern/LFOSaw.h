/*
 * LFOSaw.h
 *
 *  Created on: 4 Sep 2016
 *      Author: leo
 */

#ifndef LFOSAW_H_
#define LFOSAW_H_

#include "Value.h"

template <typename W, typename A> class LFOSaw: public Value {
public:
	LFOSaw(W& wavelength_, A& peakToPeak_, Value& minimum_) :
		frame_count(0),
		value(minimum_.get()),
		wavelength(wavelength_),
		peakToPeak(peakToPeak_),
		minimum(minimum_) {}
	virtual int_fast32_t get() { return value; }
	virtual int_fast32_t next() {
		++frame_count;
		auto w = wavelength.next();
		value = (peakToPeak.next() * ( frame_count % w )) / w  + minimum.next();
		return value;
	}
private:
	uint_fast32_t frame_count;
	int_fast32_t value;
	W& wavelength;
	A& peakToPeak;
	Value& minimum;
};

#endif /* LFOSAW_H_ */
