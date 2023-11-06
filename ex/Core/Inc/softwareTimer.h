/*
 * softwareTimer.h
 *
 *  Created on: Nov 4, 2023
 *      Author: Windows
 */

#ifndef INC_SOFTWARETIMER_H_
#define INC_SOFTWARETIMER_H_

extern int flag[4]; //0:fsm, 1:scan_lde, 2:led1, 3:led2
extern int counter[4];

void setTimer(int index, int duration);
void timerRun();

#endif /* INC_SOFTWARETIMER_H_ */
