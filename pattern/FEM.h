/*
 * FEM.h
 *
 *  Created on: 20 Aug 2016
 *      Author: leo
 */

#ifndef FEM_H_
#define FEM_H_

#include "Pattern.h"
#include <random>

class FEM: public Pattern {
public:
	virtual void updateFrame(CHSV* frame);

private:
	void pluck();
	float getTotalV2();

	float positions[Pattern::num_leds][3];
	float velocities[Pattern::num_leds][3];

	static std::default_random_engine rand_engine;
	static std::uniform_int_distribution<int> any_led;
	static constexpr float max_pluck = 1024;
	static std::uniform_real_distribution<float> pluck_size;

	static constexpr float min_v2_per_led = 1000;
	static constexpr float drag = 0.99;
	static constexpr float return_coef = 0.1;

	static const size_t end_i = Pattern::num_leds;
};

#endif /* FEM_H_ */
