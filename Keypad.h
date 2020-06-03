#include "stdint.h"
#include "C:/Keil/EE319Kware/inc/tm4c123gh6pm.h"
#include "std_types.h"
#ifndef KEYPAD_H_
#define KEYPAD_H_


#define N_col 4
#define N_row 4
#define Keypad_ROWS_DATA         GPIO_PORTD_DATA_R // ROWS ON PORT D 
#define KeyPad_ROWS_DIR          GPIO_PORTD_DIR_R
#define Keypad_COLUMNS_DATA      GPIO_PORTC_DATA_R //COLUMNS ON PORT C
#define KeyPad_COLUMNS_DIR       GPIO_PORTC_DIR_R
 /* Check if a specific bit is cleared in any register and return true if yes */
#define BIT_IS_CLEAR(REG,BIT) ( !(REG & (1<<BIT)) )

/***  functions proto types *///
uint16 KeyPad_getPressedKey(void);
#endif /*KEYPAD_H_*/
