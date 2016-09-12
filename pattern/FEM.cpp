/*
 * FEM.cpp
 *
 *  Created on: 20 Aug 2016
 *      Author: leo
 */

#include "FEM.h"

std::default_random_engine FEM::rand_engine;
std::uniform_int_distribution<int> FEM::any_led(0,Pattern::num_leds);
std::uniform_real_distribution<float> FEM::pluck_size(max_pluck/32, max_pluck);

void FEM::updateFrame(CHSV* frame) {
	if (getTotalV2() < min_v2_per_led * Pattern::num_leds) {
		pluck();
	}
	// Update positions
	for (int i = 0; i < end_i; ++i) {
		for (int j = 0; j < 3; ++j) {
			positions[i][j] += velocities[i][j];
		}
	}
	// Update velocities
	for (int j = 0; j < 3; ++j) {
		velocities[0][j] = velocities[0][j] * drag
			- (positions[0][j] * 2 + positions[1][j]) * return_coef / 3 ;
	}
	for (int i = 1; i < end_i - 1; ++i) {
		for (int j = 0; j < 3; ++j) {
			velocities[i][j] = velocities[i][j] * drag
				- (positions[i - 1][j] + positions[i][j] + positions[i + 1][j]) * return_coef / 4;
		}
	}
	for (int j = 0; j < 3; ++j) {
		velocities[end_i][j] = velocities[end_i][j] * drag
			- (positions[end_i - 1][j] + positions[end_i][j] * 2) * return_coef / 3 ;
	}
	// convert positions to HSV & return
	for (int i = 0; i < end_i; ++i) {
		for (int j = 0; j < 3; ++j) {
			frame[i].raw[j] = positions[i][j];
		}
	}
}

void FEM::pluck() {
	auto led = any_led(rand_engine);
	for (int j = 2; j < 3; ++j) {
		positions[led][j] = pluck_size(rand_engine);
	}
}

float FEM::getTotalV2() {
	float totalV2 = 0;
	for (int i = 0; i < end_i; ++i) {
		for (int j = 0; j < 3; ++j) {
			totalV2 += velocities[i][j] * velocities[i][j];
		}
	}
	return totalV2;
}
