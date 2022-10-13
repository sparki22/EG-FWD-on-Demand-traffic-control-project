/*
 * types.h
 *
 * Created: 9/29/2022 2:19:20 PM
 *  Author: ahmed salah
 */ 


#ifndef TYPES_H_
#define TYPES_H_


typedef unsigned char uint8_t;
//value defines
#define LOW 0
#define HIGH 1
//SET,CLEAR,TOGGLE,READ
#define SET_BIT(X,BIT_NO) X|=(1<<BIT_NO)
#define CLR_BIT(X,BIT_NO) X&=~(1<<BIT_NO)
#define READ_BIT(X,BIT_NO) ((X&(1<<BIT_NO))>>BIT_NO)
#define TOGGLE_BIT(X,BIT_NO) X^=(1<<BIT_NO)
//port names
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

/************************************************************************/
/* port NAMES                                                                     */
/************************************************************************/
#define  car_Traffic PORT_A
#define  pedestrains_Traffic PORT_B

/************************************************************************/
/* PIN names                                                                     */
/************************************************************************/
#define LED_green 0
#define LED_yellow 1
#define LED_red 2

/************************************************************************/
/* BUTTON PORT                                                                     */
/************************************************************************/
#define BUTTON_PORT PORT_D

/************************************************************************/
/* BUTTON PIN                                                                     */
/************************************************************************/
#define BUTTON_PIN 2

//DURING NORMAL MODE RUNNING POSSIBLE CASES
typedef enum EN_car_cases{
	carGreenOnly,carGreenYellow,carRedOnly,carRedYellow
}EN_car_cases;

#endif /* TYPES_H_ */