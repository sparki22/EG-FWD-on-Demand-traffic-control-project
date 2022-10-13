/*
 * registers.h
 *
 * Created: 9/29/2022 2:19:08 PM
 *  Author: ahmed salah 
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_

/*********************************************************************/
/*DIO REGISTERS                                                      */
/*********************************************************************/

//PORTA registers
#define  PORTA *((volatile uint8_t*)0x3B) //PORT register is 8-bit register and 0x3B is its address so we need to cast it and dereference so the assignment becomes valid
//PORTA now is pointer to the 8-bit register(uint8_t has 8 bits) address(0x3B) and to be able to use it we need to dereference it
#define  DDRA *((volatile uint8_t*)0x3A) //8-bit register
#define  PINA *((volatile uint8_t*)0x39)

//PORT B REGISTERS
#define  PORTB *((volatile uint8_t*)0x38)//8-BIT REGISTER
#define  DDRB *((volatile uint8_t*)0x37) //8-BIT REGISTER
#define  PINB *((volatile uint8_t*)0x36) //8-BIT REGISTER

//PORT C REGISTERS
#define  PORTC *((volatile uint8_t*)0x35)//8-BIT REGISTER
#define  DDRC *((volatile uint8_t*)0x34) //8-BIT REGISTER
#define  PINC *((volatile uint8_t*)0x33) //8-BIT REGISTER
//PORT D REGISTERS
#define  PORTD *((volatile uint8_t*)0x32)//8-BIT REGISTER
#define  DDRD *((volatile uint8_t*)0x31) //8-BIT REGISTER
#define  PIND *((volatile uint8_t*)0x30) //8-BIT REGISTER
/************************************************************************/
/* TIMER 0 REGISTERS                                                                     */
/************************************************************************/
#define  TCCR0 *((volatile uint8_t*)0x53)//8-BIT REGISTER
#define  TCNT0 *((volatile uint8_t*)0x52) //8-BIT REGISTER
#define  TIFR *((volatile uint8_t*)0x58) //8-BIT REGISTER


/************************************************************************/
/* STATUS REGISTER                                                                     */
/************************************************************************/
#define SREG *((volatile uint8_t*)0x5F)


/************************************************************************/
/* INTERRUPTS REGIESTERS                                                                     */
/************************************************************************/
//REGISTER RESBONSIBLE FOR CHOOSING INTERRUPT SENSE
#define MCUCR *((volatile uint8_t*)0x55)
//FOR ENABLING THE INTERRUPT
#define GICR *((volatile uint8_t*)0x5B)
//INTERRUPT FLAG REGISTER
#define GIFR *((volatile uint8_t*)0x5A)

/************************************************************************/
/* REGIESTER RESBONSIBLE FOR TIMER INTERRUPTS                                                                     */
/************************************************************************/
#define TIMSK *((volatile uint8_t*)0x59)
#endif /* REGISTERS_H_ */