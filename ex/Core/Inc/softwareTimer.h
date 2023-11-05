/*
 * softwareTimer.h
 *
 *  Created on: Nov 4, 2023
 *      Author: Windows
 */

#ifndef INC_SOFTWARETIMER_H_
#define INC_SOFTWARETIMER_H_

extern int flag[2];

void setTimer(int index, int duration);
void timerRun();

#endif /* INC_SOFTWARETIMER_H_ */
