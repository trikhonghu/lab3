/*
 * global.h
 *
 *  Created on: Nov 2, 2023
 *      Author: Windows
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include "input_reading.h"
#include "softwareTimer.h"

#define INIT			1
#define AUTO_RED_GREEN	2
#define AUTO_RED_YELLOW	3
#define AUTO_GREEN_RED	4
#define AUTO_YELLOW_RED	5
#define COUNT_YELLOW	200

extern int status;
extern int count_red;
extern const uint8_t led7_seg_buffer[10];
extern uint8_t led_buffer[4];

#endif /* INC_GLOBAL_H_ */
