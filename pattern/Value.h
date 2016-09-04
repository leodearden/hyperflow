/*
 * Value.h
 *
 *  Created on: 4 Sep 2016
 *      Author: leo
 */

#ifndef VALUE_H_
#define VALUE_H_

class Value {
public:
	virtual int_fast32_t get() = 0;
	virtual int_fast32_t next() = 0;
	virtual ~Value() {};
};

#endif /* VALUE_H_ */
