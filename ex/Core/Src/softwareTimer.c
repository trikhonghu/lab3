/*
 * softwareTimer.c
 *
 *  Created on: Nov 4, 2023
 *      Author: Pham Van Tri
 */

#include "softwareTimer.h"
#include "global.h"

int counter[4] = {0};
int flag[4] = {0};

void setTimer(int index ,int duration){
	if(index < 2){
		counter[index] = duration;
		flag[index] = 0;
	}
}

void timerRun(void){
	for(int i =0; i<3; i++){
		if(counter[i] > 0){
			counter[i]--;
			if(counter[i] <= 0){
			flag[i] = 1;
			}
		}
	}
}
