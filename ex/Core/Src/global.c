/*
 * global.c
 *
 *  Created on: Nov 2, 2023
 *      Author: Windows
 */

#include "global.h"

int status = INIT;
int count_red = 5;

const uint8_t led7_seg_buffer[10]= {
	0b11000000,
	0b11111001,
	0b10100100,
	0b10110000,
	0b10011001,
	0b10010010,
	0b10000010,
	0b11111000,
	0b10000000,
	0b10010000
};
uint8_t led_buffer[4] = {3, 4, 5, 6};
