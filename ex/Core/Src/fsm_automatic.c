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
 INIT				1
 AUTO_RED_GREEN		2
 AUTO_RED_YELLOW	3
 AUTO_GREEN_RED		4
 AUTO_YELLOW_RED	5

 The yellow light is initialized for a fixed period of 2 seconds

 ------------------------------------------------------------------*/


void fsm_automatic_run(void){
	//flag[2]:ledTraffic1, flag[3]:ledTraffic2
	switch (status) {
		case INIT:
			//TO DO
			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
			HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET);

			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
			HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);

			if(mode == 1){
				led_buffer[0]=0;
				led_buffer[1]=0;

				led_buffer[2] =0;
				led_buffer[3] =0;
			}

			status = AUTO_RED_GREEN;
			//counter[1]
			setTimer(0, count_green*100);
			break;
		case AUTO_RED_GREEN:
			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, RESET);
			HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET);

			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
			HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, RESET);

			if(mode == 1){
				led_buffer[0] = (count_yellow*100 + counter[0])/1000;
				led_buffer[1] = ((count_yellow*100 + counter[0])/100)%10;

				led_buffer[2] = (counter[0])/1000;
				led_buffer[3] = ((counter[0])/100)%10;
			}

			if(flag[0] == 1){
				status = AUTO_RED_YELLOW;
				setTimer(0, count_yellow*100);
			}
			break;
		case AUTO_RED_YELLOW:
			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, RESET);
			HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET);

			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
			HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, RESET);
			HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);

			if(mode == 1){
				led_buffer[0] = (counter[0])/1000;
				led_buffer[1] = ((counter[0])/100)%10;

				led_buffer[2] = (counter[0])/1000;
				led_buffer[3] = ((counter[0])/100)%10;
			}

			if(flag[0] == 1){
				status = AUTO_GREEN_RED;
				setTimer(0, count_green*100);
			}
			break;
		case AUTO_GREEN_RED:
			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
			HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, RESET);

			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, RESET);
			HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);

			if(mode == 1){
				led_buffer[0] = (counter[0])/1000;
				led_buffer[1] = ((counter[0])/100)%10;

				led_buffer[2] = (count_yellow*100 + counter[0])/1000;
				led_buffer[3] = ((count_yellow*100 + counter[0])/100)%10;
			}

			if(flag[0] == 1){
				status = AUTO_YELLOW_RED;
				setTimer(0, count_yellow * 100);
			}

			break;
		case AUTO_YELLOW_RED:
			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
			HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, RESET);
			HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET);

			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, RESET);
			HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);

			if(mode == 1){
				led_buffer[0] = (counter[0])/1000;
				led_buffer[1] = ((counter[0])/100)%10;

				led_buffer[2] = (counter[0])/1000;
				led_buffer[3] = ((counter[0])/100)%10;
			}

			if(flag[0] == 1){
				status = AUTO_RED_GREEN;
				setTimer(0, count_green*100);
			}

			break;
		default:

			break;
	}
}
