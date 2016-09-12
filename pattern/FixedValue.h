/*
 * FixedValue.h
 *
 *  Created on: 4 Sep 2016
 *      Author: leo
 */

#ifndef FIXEDVALUE_H_
#define FIXEDVALUE_H_

#include "Value.h"

template <int_fast32_t v> class FixedValue: public Value {
public:
	virtual int_fast32_t get() { return v; }
	virtual int_fast32_t next() { return v; }
};



#endif /* FIXEDVALUE_H_ */
