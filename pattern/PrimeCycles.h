/*
 * PrimeSines.h
 *
 *  Created on: 16 Sep 2016
 *      Author: leo
 */

#ifndef PRIMECYCLES_H_
#define PRIMECYCLES_H_

#include "Pattern.h"

class PrimeCycles: public Pattern {
public:
	PrimeCycles() : frame_count(0) {}
	virtual void updateFrame(CHSV* frame);
private:
	uint_fast32_t frame_count;
	static constexpr int h_period = 13;
	static constexpr int s_period = 17;
	static constexpr int v_period = 29;
};

#endif /* PRIMECYCLES_H_ */
