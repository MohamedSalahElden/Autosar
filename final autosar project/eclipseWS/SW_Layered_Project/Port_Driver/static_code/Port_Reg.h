/*
 * Port_Reg.h
 *
 *  Created on: Mar 3, 2020
 *      Author: SALAH
 */

#ifndef PORT_DRIVER_STATIC_CODE_PORT_REG_H_
#define PORT_DRIVER_STATIC_CODE_PORT_REG_H_


#include "../../Std_Types.h"


#define PORTA_REG	( *(volatile 	uint8 * const)(0X3B) )
#define DDRA_REG	( *(volatile 	uint8 * const)(0X3A) )
#define PINA_REG	( *(volatile 	uint8 * const)(0X39) )
#define PORTB_REG	( *(volatile	uint8 * const)(0X38) )
#define DDRB_REG	( *(volatile	uint8 * const)(0X37) )
#define PINB_REG	( *(volatile	uint8 * const)(0X36) )
#define PORTC_REG	( *(volatile	uint8 * const)(0X35) )
#define DDRC_REG	( *(volatile	uint8 * const)(0X34) )
#define PINC_REG	( *(volatile	uint8 * const)(0X33) )
#define PORTD_REG	( *(volatile	uint8 * const)(0X32) )
#define DDRD_REG	( *(volatile	uint8 * const)(0X31) )
#define PIND_REG	( *(volatile	uint8 * const)(0X30) )



#endif /* PORT_DRIVER_STATIC_CODE_PORT_REG_H_ */
