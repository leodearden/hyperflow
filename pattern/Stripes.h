/*
 * Stripes.h
 *
 *  Created on: 22 Aug 2016
 *      Author: leo
 */

#ifndef STRIPES_H_
#define STRIPES_H_

#include "Pattern.h"
#include "Value.h"
#include <cstdint>

class Stripes: public Pattern {
public:
	Stripes(Value& width);
	virtual void updateFrame(CHSV* frame);

private:
	uint_fast32_t frame_count;

	Value& width;
};

#endif /* STRIPES_H_ */
