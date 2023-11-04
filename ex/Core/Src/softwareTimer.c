/*
 * softwareTimer.c
 *
 *  Created on: Nov 4, 2023
 *      Author: Pham Van Tri
 */

#include "softwareTimer.h"

int counter = 0;
int flag = 0;

void setTimer(int duration){
		counter = duration;
		flag = 0;
}

void timerRun(void){
	if(counter > 0){
		counter--;
		if(counter <= 0){
			flag = 1;
		}
	}
}
