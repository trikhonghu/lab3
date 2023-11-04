/*
 * input_processing.c
 *
 *  Created on: Nov 2, 2023
 *      Author: Pham Van Tri
 */
#include "main.h"
#include "input_reading.h"
#include "input_processing.h"
//aim to work with more than 1 button
#define NO_OF_BUTTONS					1 //num of buttons
//timer interrupt duration is 10ms, to to pass 1 second,
//we need to jump the interrupt 100 times
#define DURATION_FOR_AUTO_INCREASING	100
#define BUTTON_IS_PRESSED				GPIO_PIN_RESET
#define BUTTON_IS_RELEASED				GPIO_PIN_SET
//the buffer that the final result is stored after debouncing
static GPIO_PinState buttonBuffer[NO_OF_BUTTONS];
//we define two buffers for debouncing
static GPIO_PinState debounceButtonBuffer1[NO_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer2[NO_OF_BUTTONS];
//define flag for a button pressed more than 1 second
static uint8_t flagForButtonPress1s [ NO_OF_BUTTONS ];
//we define counter for automatically increasing value after the button is pressed more than 1 sec
static uint16_t counterForButtonPress1s[NO_OF_BUTTONS];
//read input
void button_reading(void){
	for(char i = 0; i < NO_OF_BUTTONS; i++){
		debounceButtonBuffer2[i] = debounceButtonBuffer1[i];
		debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(BUTTON_1_GPIO_Port, BUTTON_1_Pin);
		if(debounceButtonBuffer1[i] == debounceButtonBuffer2[i]){
			buttonBuffer[i] = debounceButtonBuffer1[i];
			if(buttonBuffer[i] == BUTTON_IS_PRESSED){
				//if a button is pressed then we start counting
				if(counterForButtonPress1s[i] < DURATION_FOR_AUTO_INCREASING){
					counterForButtonPress1s[i]++;
				}else{
					//flag turn on when being pressed more than 1s
					//since the button is pressed
					flagForButtonPress1s[i] = 1;
					//to do
				}
			}else{
				counterForButtonPress1s[i] = 0;
				flagForButtonPress1s[i] = 0;
			}
		}
	}
}

unsigned char is_button_pressed(uint8_t index){
	if(index >= NO_OF_BUTTONS) return 0;
	return (buttonBuffer[index] == BUTTON_IS_PRESSED);
}

unsigned char is_button_pressed_1s(unsigned char index){
	if(index >= NO_OF_BUTTONS) return 0xff;
	return (flagForButtonPress1s[index] == 1);
}
/*--------------------------------------------------------------*/
/*
 * Finate State Machine
 *
 */
 enum ButtonState{BUTTON_RELEASED, BUTTON_PRESSED, BUTTON_PRESSED_MORE_THAN_1_SECOND};
 enum ButtonState buttonState = BUTTON_RELEASED;

 void fsm_for_input_processing(void){
	 switch (buttonState) {
		case BUTTON_RELEASED:
			if(is_button_pressed(0)){
				buttonState = BUTTON_PRESSED;
			}
			break;
		case BUTTON_PRESSED :
			if (! is_button_pressed (0)){
				buttonState = BUTTON_RELEASED ;
			} else {
				if( is_button_pressed_1s (0) ){
					buttonState = BUTTON_PRESSED_MORE_THAN_1_SECOND ;
				}
			}
			break ;
		case BUTTON_PRESSED_MORE_THAN_1_SECOND :
			if (! is_button_pressed (0)){
				buttonState = BUTTON_RELEASED ;
			}
			// todo
			break ;
		default:
			break;
	 }
 }
