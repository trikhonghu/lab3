/*
 * global.c
 *
 *  Created on: Nov 2, 2023
 *      Author: Windows
 */

#include "global.h"

int status = INIT;
int key_sw = 0;
int count_red = 5;
uint8_t count_led1 =0;
uint8_t count_led2 =0;

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
