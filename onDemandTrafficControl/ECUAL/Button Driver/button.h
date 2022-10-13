/*
 * button.h
 *
 * Created: 9/29/2022 1:55:26 PM
 *  Author:ahmed salah
 */ 

//functions needed:
//init button to be INPUT,Read the current button state
#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../utilities/MACROS.h"
#include "../../MCAL/Interrupts/interrupt.h"
//BUTTON STATE
#define LOW  0
#define HIGH 1
#include "../../MCAL/DIO Driver/dio.h"
//initialize
void  BUTTON_init(uint8_t buttonPort,uint8_t buttonPin);
//button read
void BUTTON_read(uint8_t buttonPort,uint8_t buttonPin,uint8_t *value);

#endif /* BUTTON_H_ */