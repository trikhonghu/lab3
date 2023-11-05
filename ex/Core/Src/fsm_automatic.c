/*
 * fsm_automatic.c
 *
 *  Created on: Nov 2, 2023
 *      Author: Windows
 */
#include "fsm_automatic.h"
#include "global.h"
/*-----------------------------------------------------------------
 INIT				1
 AUTO_RED_GREEN		2
 AUTO_RED_YELLOW	3
 AUTO_GREEN_RED		4
 AUTO_YELLOW_RED	5

 The yellow light is initialized for a fixed period of 2 seconds

 ------------------------------------------------------------------*/


void fsm_automatic_run(void){
	//count_led1++;
	//count_led2++;
	switch (status) {
		case INIT:
			//TO DO
			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
			HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET);

			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
			HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);

			status = AUTO_RED_GREEN;
			//counter[1]
			setTimer(0, (count_red*100)-COUNT_YELLOW);
			break;
		case AUTO_RED_GREEN:
			if(count_led1 % 100 == 0){
				led_buffer[0]=(count_red*100-count_led1)/1000;
				led_buffer[1]=(count_red*100-count_led1)%1000;
			}

			if(count_led2 % 100 == 0){
				led_buffer[2] = (count_red*100 - COUNT_YELLOW - count_led2)/1000;
				led_buffer[3] = (count_red*100 - COUNT_YELLOW - count_led2)%1000;
			}

			if(count_led2 == count_red*100 - COUNT_YELLOW)
				count_led2 = 0;

			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, RESET);
			HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET);

			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
			HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, RESET);

			if(flag[0] == 1){
				status = AUTO_RED_YELLOW;
				setTimer(0, 200);
			}
			break;
		case AUTO_RED_YELLOW:
			if(count_led1 % 100 == 0){
				led_buffer[0]=(count_red*100-count_led1)/1000;
				led_buffer[1]=(count_red*100-count_led1)%1000;
			}

			if(count_led1 == count_red){
				count_led1 = 0;
			}

			if(count_led2 % 100 == 0){
				led_buffer[2] = (COUNT_YELLOW - count_led2)/1000;
				led_buffer[3] = (COUNT_YELLOW - count_led2)%1000;
			}

			if(count_led2 == COUNT_YELLOW)
				count_led2 = 0;

			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, RESET);
			HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET);

			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
			HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, RESET);
			HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);

			if(flag[0] == 1){
				status = AUTO_GREEN_RED;
				setTimer(0, (count_red*100)-COUNT_YELLOW);
			}
			break;
		case AUTO_GREEN_RED:
			if(count_led2 % 100 == 0){
				led_buffer[2]=(count_red*100-count_led2)/1000;
				led_buffer[3]=(count_red*100-count_led2)%1000;
			}

			if(count_led1 % 100 == 0){
				led_buffer[0] = (count_red*100 - COUNT_YELLOW - count_led2)/1000;
				led_buffer[1] = (count_red*100 - COUNT_YELLOW - count_led2)%1000;
			}

			if(count_led1 == count_red*100 - COUNT_YELLOW)
				count_led1 = 0;

			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
			HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, RESET);

			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, RESET);
			HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);

			if(flag[0] == 1){
				status = AUTO_YELLOW_RED;
				setTimer(0, 200);
			}
			break;
		case AUTO_YELLOW_RED:
			if(count_led2 % 100 == 0){
				led_buffer[2]=(count_red*100-count_led2)/1000;
				led_buffer[3]=(count_red*100-count_led2)%1000;
			}

			if(count_led2 % 100 == 0){
				led_buffer[2] = (COUNT_YELLOW - count_led2)/1000;
				led_buffer[3] = (COUNT_YELLOW - count_led2)%1000;
			}

			if(count_led2 == COUNT_YELLOW)
				count_led2 = 0;

			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
			HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, RESET);
			HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET);

			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, RESET);
			HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);

			if(count_led2 == count_red){
				count_led2 = 0;
			}

			if(flag[0] == 1){
				status = AUTO_RED_GREEN;
				setTimer(0, (count_red*100)-COUNT_YELLOW);
			}
			break;
		default:

			break;
	}
}
