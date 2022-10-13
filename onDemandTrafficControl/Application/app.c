/*
 * app.c
 *
 * Created: 9/29/2022 2:00:30 PM
 *  Author: ahmed salah
 */ 
#include "app.h"

void APP_init(){
	//initializing leds as outputs
	LED_init(car_Traffic,LED_green);
	LED_init(car_Traffic,LED_red);
	LED_init(car_Traffic,LED_yellow);
	LED_init(pedestrains_Traffic,LED_green);
	LED_init(pedestrains_Traffic,LED_red);
	LED_init(pedestrains_Traffic,LED_yellow);
	//initializing button as input
	BUTTON_init(BUTTON_PORT,BUTTON_PIN);
	//selecting timer mode
	TIMER0_init();
	//enable global interrupts
	INTERRUPT_GLOBAL_EN();
	//enable timer 0 interrupts
	INTERRUPT_TIMER0_EN();
	//selecting the interrupt sense to rising edge
	INT0_init();
	//start listening for the interrupt
	INTERRUPT0_EN();
	//set address of call back function
	setOvfCallback(LED_toggle);
}
uint8_t carledState=0;
//as an indicator for the button click to eliminate the double click(only works if clicked=0)
uint8_t clicked=0;
void APP_start(){
	//starting as normal mode with green led
	 if(carledState==carGreenOnly){
		 
		 LED_on(car_Traffic,LED_green);
		 LED_off(car_Traffic,LED_yellow);
		 LED_off(car_Traffic,LED_red);
		 //checking if we are normal mode we need to keep red led of pedesterians on
		 if(clicked==0)
		 LED_on(pedestrains_Traffic,LED_red);
		 //wait for five seconds
		 TIMER0_delay();
		 //go to next state
		 carledState++;
	 }
	 //next state is green still on and yellow blinking using the timer over flow
	 if(carledState==carGreenYellow){
		 //during this delay yellow led blinks every time overflow happens
		 TIMER0_delay();
		 
		 if(clicked==1)
		  LED_off(pedestrains_Traffic,LED_red);
		 carledState++;
	 }
	 if(carledState==carRedOnly){
		
		 LED_off(car_Traffic,LED_green);
		 LED_off(car_Traffic,LED_yellow);
		 LED_on(car_Traffic,LED_red);
		 //checking if we are normal mode we need to keep red led of pedesterians on
		 if(clicked==0)
		 LED_on(pedestrains_Traffic,LED_red);
		 //checking if pedesterian mode we need to turn on green
		 else if(clicked==1)
		 LED_on(pedestrains_Traffic,LED_green);
		 TIMER0_delay();
		 carledState++;
	 }
	 if(carledState==carRedYellow){
		 
		
		 TIMER0_delay();
		 LED_off(pedestrains_Traffic,LED_green);
		 //setting the ledstate to 0 to begin from the first case
		 carledState=0;
		 //setting clicked flag to 0 again to be able to execute the ISR when clicked next time
		 clicked=0;
	 }
	}
	
	
