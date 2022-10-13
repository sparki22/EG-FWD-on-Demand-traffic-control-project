/*
 * interrupt.h
 *
 * Created: 9/29/2022 2:09:45 PM
 *  Author: ahmed salah
 */ 
//functions needed by interrupts:
//enable global interrupts,choose interrupt sense,enable external interrupt,ISR	,ENABLE T0 overflow interrupt

#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include "../../utilities/registers.h"
#include "../../utilities/MACROS.h"

//in this project we only use INT0(the button pin)
#define EXT_INT_0 __vector_1
//defining timer 0 overflow vector
#define TIMER0_OF_VECT __vector_11
#define ISR(INT_VECT) void INT_VECT(void) __attribute__ ((signal,used));\
void INT_VECT(void)

//prototypes
void INTERRUPT_GLOBAL_EN();
void INT0_init();
void INTERRUPT0_EN();
void INTERRUPT_TIMER0_EN();

#endif /* INTERRUPT_H_ */