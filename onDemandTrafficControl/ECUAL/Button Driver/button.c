/*
 * button.c
 *
 * Created: 9/29/2022 1:55:10 PM
 *  Author: ahmed salah
 */ 
#include "button.h"
#include "../../MCAL/Interrupts/interrupt.h"

uint8_t carledState;
uint8_t overflowsCounter;
extern uint8_t clicked;
void  BUTTON_init(uint8_t buttonPort,uint8_t buttonPin){
	DIO_init(buttonPort,buttonPin,IN);
}
void BUTTON_read(uint8_t buttonPort,uint8_t buttonPin,uint8_t *value){
	DIO_read(buttonPort,buttonPin,value);
}



//ISR executed when button pressed

ISR(EXT_INT_0){
	if(clicked==0){
		//using clicked as  flag to eliminate the double click
		//check the cases when did we press the button
		if(carledState==carGreenOnly){
			//we need to skip the remaining timer green led has to stay so set the overflowcounter to 20(full)
			overflowsCounter=20;
			
		}else if(carledState==carGreenYellow){
			//we need to reset the timer of the yellow leds stays
			TIMER0_reset();
		}else if(carledState==carRedOnly){
			//we need timer reset if pressed when cars traffic is red and turn ON green pedesterians traffic
			TIMER0_reset();
			LED_on(pedestrains_Traffic,LED_green);
			LED_off(pedestrains_Traffic,LED_red);
		}else if(carledState==carRedYellow){
			LED_off(pedestrains_Traffic,LED_red);
			LED_on(pedestrains_Traffic,LED_green);
		TIMER0_reset();
		
			
		}
		}
	clicked=1;
}
