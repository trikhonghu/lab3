/*
 * softwareTimer.c
 *
 *  Created on: Nov 4, 2023
 *      Author: Pham Van Tri
 */

#include "softwareTimer.h"
#include "global.h"

int counter[4] = {0}; //0:fsm_traffic_1, 1:scan_led, 2:fsm_traffic_2, 3:Toggle 2Hz
int flag[4] = {0};

void setTimer(int index ,int duration){
	if(index < 4){
		counter[index] = duration;
		flag[index] = 0;
	}
}

void timerRun(void){
	for(int i =0; i<4; i++){
		if(counter[i] > 0){
			counter[i]--;
			if(counter[i] <= 0){
			flag[i] = 1;
			}
		}
	}
}
