/*
 * Stripes.h
 *
 *  Created on: 22 Aug 2016
 *      Author: leo
 */

#ifndef STRIPES_H_
#define STRIPES_H_

#include "Pattern.h"
#include <cstdint>

class Stripes: public Pattern {
public:
	Stripes();
	virtual void updateFrame(CHSV* frame);

private:
	uint_fast32_t frame_count;

	static const int stripe_y = 8;
};

#endif /* STRIPES_H_ */
