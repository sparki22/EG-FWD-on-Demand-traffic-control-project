/*
 * timer.h
 *
 * Created: 9/29/2022 2:00:13 PM
 *  Author: ahmed salah
 */ 
//functions needed by timer driver:
//start,stop,delay,initializing,set init value,resetTimer
#ifndef TIMER_H_
#define TIMER_H_

#include "../../utilities/MACROS.h"
#include "../../utilities/registers.h"
#include "../Interrupts/interrupt.h"
#define start_value 11
//prototypes
void TIMER0_init();
void TIMER0_start();
void TIMER0_stop();
void TIMER0_delay();
//setting the initial value
void TIMER0_set_value(uint8_t value);
void TIMER0_reset();

#endif /* TIMER_H_ */