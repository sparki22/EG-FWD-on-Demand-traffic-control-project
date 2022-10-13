/*
 * app.h
 *
 * Created: 9/29/2022 2:00:40 PM
 *  Author: ahmed salah
 */ 


#ifndef APP_H_
#define APP_H_
#include "../ECUAL/LED Driver/LED.h"
#include "../ECUAL/Button Driver/button.h"
#include "../MCAL/Interrupts/interrupt.h"
#include "../MCAL/Timer/timer.h"


//PROTOTYPES
void APP_init();
void APP_start();

#endif /* APP_H_ */