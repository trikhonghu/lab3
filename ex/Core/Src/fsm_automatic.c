/*
 * fsm_automatic.c
 *
 *  Created on: Nov 2, 2023
 *      Author: Windows
 */
#include "fsm_automatic.h"
#include "global.h"
#include "softwareTimer.h"
/*-----------------------------------------------------------------

 INIT			1
 AUTO_RED		2
 AUTO_YELLOW	3
 AUTO_GREEN		4

 ------------------------------------------------------------------*/


void fsm_automatic_run1(void){
	led_buffer[0] = (counter[0]/count_inter)/10;
	led_buffer[1] = (counter[0]/count_inter)%10;

	switch (status[0]) {
		case INIT:
			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
			HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET);

			status[0] = AUTO_RED;
			setTimer(0, count_red*count_inter);
			break;
		case AUTO_RED:
			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, RESET);
			HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET);

			if(flag[0] == 1){
				status[0] = AUTO_GREEN;
				setTimer(0, count_green*count_inter);
			}
			break;
		case AUTO_GREEN:
			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
			HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, RESET);

			if (flag[0] == 1) {
				status[0] = AUTO_YELLOW;
				setTimer(0, count_yellow*count_inter);
			}
			break;
		case AUTO_YELLOW:
			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
			HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, RESET);
			HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET);

			if (flag[0] == 1) {
				status[0] = AUTO_RED;
				setTimer(0, count_red*count_inter);
			}
			break;
		default:
			break;
	}
}

void fsm_automatic_run2(void){
	led_buffer[2] = counter[2]/1000;
	led_buffer[3] = (counter[2]/100)%10;

	switch (status[1]) {
		case INIT:
			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
			HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);

			status[1] = AUTO_GREEN;
			setTimer(2, count_green*count_inter);
			break;
		case AUTO_GREEN:
			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
			HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, RESET);

			if(flag[2] == 1){
				status[1] = AUTO_YELLOW;
				setTimer(2, count_yellow*count_inter);
			}
			break;
		case AUTO_YELLOW:
			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
			HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, RESET);
			HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);

			if(flag[2] == 1){
				status[1] = AUTO_RED;
				setTimer(2, count_red*count_inter);
			}
			break;
		case AUTO_RED:
			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, RESET);
			HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);

			if(flag[2] == 1){
				status[1] = AUTO_GREEN;
				setTimer(2, count_green*count_inter);
			}
		default:
			break;
	}
}
