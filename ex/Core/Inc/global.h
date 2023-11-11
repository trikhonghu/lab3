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

#define INIT		1
#define AUTO_RED	2
#define AUTO_YELLOW	3
#define AUTO_GREEN	4

extern uint32_t			prescaller;
extern uint32_t			counter_;

extern uint32_t			count_inter;

extern uint8_t			mode;

extern uint8_t 			status[2];
extern uint8_t 			key_sw;

extern uint8_t 			count_red;
extern uint8_t			count_yellow;
extern uint8_t			count_green;

extern const uint8_t 	led7_seg_buffer[10];
extern uint8_t 			led_buffer[4];

extern uint8_t 			count_led1;
extern uint8_t 			count_led2;

extern uint8_t			temp[3];
#endif /* INC_GLOBAL_H_ */
