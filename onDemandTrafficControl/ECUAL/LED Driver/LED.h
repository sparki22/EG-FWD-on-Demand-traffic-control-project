/*
 * LED.h
 *
 * Created: 9/29/2022 1:56:09 PM
 *  Author: ahmed salah
 */ 

//functions needed:
//init led to be output,turn on,turn off,toggle the current state
#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO Driver/dio.h"

void LED_init(uint8_t ledPort,uint8_t ledPin);
void LED_on(uint8_t ledPort,uint8_t ledPin);
void LED_off(uint8_t ledPort,uint8_t ledPin);
void LED_toggle(uint8_t ledPort,uint8_t ledPin);




#endif /* LED_H_ */