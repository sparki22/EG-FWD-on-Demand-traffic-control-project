/*
 * timer.c
 *
 * Created: 9/29/2022 1:57:17 PM
 *  Author: ahmed salah
 */ 
//calculations
/*
choosing 1024 prescaler
tickTime=1.024ms
maxDelay of 1 over flow=2^8*1.024ms
no.of over flows needed to make 5 seconds=5000/maxDelay=20
INITIAL TIMER: 11
*/
#define NUMBER_OF_OVERFLOWS 20

#include "timer.h"


//setting pointer to function variable to call functions from upper layers
//in our case we will need to call the LED_off function to toggle the yellow led state to blink
void static(*ovfCallback)(uint8_t port,uint8_t pin);
void setOvfCallback(void(*Callback)(uint8_t port,uint8_t pin)){
	ovfCallback=Callback;
}
extern uint8_t carledState;
extern uint8_t pedledState;
extern uint8_t normalMode;
extern uint8_t overflowsCounter=0;
uint8_t clicked;
void TIMER0_init(){
	//select mode of timer(normnal mode);
	TCCR0=0X00;
	TIMER0_set_value(start_value);
}
void TIMER0_start(){
	//setting prescaler to 1024
	TCCR0|=(1<<0)|(1<<2);
	//every time overflow happens ISR executed which increases the number of overflowcounter by 1
	//counting 20 overflows	
	while(overflowsCounter<NUMBER_OF_OVERFLOWS);
}
void TIMER0_stop(){
	//when setting no prescaler timer stops
	TCCR0=0x00;
	//now timer stopped so we need to set overflowscounter to 0 to start over again
	overflowsCounter=0;
}
void TIMER0_delay(){
	TIMER0_start();
	TIMER0_stop();
}
void TIMER0_set_value(uint8_t value){
	TCNT0=value;
}
void TIMER0_reset(){
	//this function resets the 5 second timer to begin from very first time
	TIMER0_set_value(start_value);
	overflowsCounter=0;
	
}
uint8_t pinValue=0;



ISR(TIMER0_OF_VECT){
	//Initial the timer again to begin from first;
	TIMER0_set_value(start_value);
	overflowsCounter++;
	//checking if the carledstate is green and yellow or red and yellow to blink the yellow led every time overflow happens
	 if(carledState==carGreenYellow && clicked==1){//ped mode
		
		ovfCallback(car_Traffic,LED_yellow);
		ovfCallback(pedestrains_Traffic,LED_yellow);
		
	}else if((carledState==carGreenYellow||carledState==carRedYellow)&&clicked==1){//ped mode
		ovfCallback(car_Traffic,LED_yellow);
		ovfCallback(pedestrains_Traffic,LED_yellow);
		
	}
	else if((carledState==carGreenYellow || carledState==carRedYellow)){//normal mode
	ovfCallback(car_Traffic,LED_yellow);
}
	
}