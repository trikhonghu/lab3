/*
 * global.c
 *
 *  Created on: Nov 2, 2023
 *      Author: Windows
 */

#include "global.h"

uint8_t mode			= 1;
uint8_t status 			= INIT;
uint8_t key_sw 			= 0;
uint8_t count_red 		= 10;
uint8_t count_yellow 	= 3;
uint8_t count_green 	= 7;
uint8_t count_led1 		=0;
uint8_t count_led2 		=0;

const uint8_t led7_seg_buffer[10] = {
    0b11000000, // 0
    0b11111001, // 1
    0b10100100, // 2
    0b10110000, // 3
    0b10011001, // 4
    0b10010010, // 5
    0b10000010, // 6
    0b11111000, // 7
    0b10000000, // 8
    0b10010000  // 9
};
uint8_t led_buffer[4] = {3, 4, 5, 6};
