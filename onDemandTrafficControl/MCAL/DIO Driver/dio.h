/*
 * dio.h
 *
 * Created: 9/29/2022 1:57:00 PM
 *  Author: ahmed salah
 */ 


#ifndef DIO_H_
#define DIO_H_


#include "../../utilities/registers.h"
#include "../../utilities/MACROS.h"



//direction defines
#define IN 0
#define OUT 1

//value defines
#define LOW 0
#define HIGH 1

//all driver functions prototypes
void DIO_init(uint8_t portNumber,uint8_t pinNumber,uint8_t direction);//initialize  dio direction  i/p or o/p and has all control registers
void DIO_write(uint8_t portNumber,uint8_t pinNumber,uint8_t value);// write data to dio
void DIO_toggle(uint8_t portNumber,uint8_t pinNumber);//toggle data
void DIO_read(uint8_t portNumber,uint8_t pinNumber,uint8_t *value);//Read dio


#endif /* DIO_H_ */