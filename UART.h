#include "stdint.h"
#include "C:/Keil/EE319Kware/inc/tm4c123gh6pm.h"

void UART_init(void);
int UART0_available(void);
char UART0_Read(void);
void UART0_write(char data);
void read_writeToUpper(void);
void init_PORTF(void);
void PortD_init(void);
void PortC_init(void);
