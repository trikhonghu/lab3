/*
 * fsm_automatic.c
 *
 *  Created on: Nov 2, 2023
 *      Author: Windows
 */
#include "fsm_automatic.h"
#include "global.h"

void fsm_automatic_run(void){
	switch (status) {
		case INIT:
			//TO DO
			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
			HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET);

			status = AUTO_RED;
			//counter[1]
			setTimer(500);
			break;
		case AUTO_RED:
			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, RESET);
			HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET);

			if(flag == 1){
				status = AUTO_GREEN;
				setTimer(300);
			}
			break;
		case AUTO_YELLOW:
			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
			HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, RESET);
			HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET);

			if(flag == 1){
				status = AUTO_RED;
				setTimer(500);
			}
			break;
		case AUTO_GREEN:
			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
			HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, RESET);

			if(flag == 1){
				status = AUTO_YELLOW;
				setTimer(200);
			}
			break;
		default:

			break;
	}
}
