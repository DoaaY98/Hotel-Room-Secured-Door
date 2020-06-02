#include "stdint.h"
#include "C:/Keil/EE319Kware/inc/tm4c123gh6pm.h"
#include "UART.h"
//assume sysclk is 80 MHz
void UART_init(void){
SYSCTL_RCGCUART_R |=0x01; //enable uart0 clock
SYSCTL_RCGCGPIO_R |=0x01;  //enable clk of portA	
UART0_CTL_R &=~ 0x01;//disable uart
UART0_IBRD_R=520;//set baudrate	int (80*10^6/16*9600)
UART0_FBRD_R=53; //fraction of baud rate	
UART0_LCRH_R=0X0070; //ENABLE FIFO ,WORD LENGTH=8 , NO PARITY
UART0_CTL_R=0X301;//enable transmission and recieving in uart	

GPIO_PORTA_AFSEL_R |=0X03;//ENABLE ALTERNATE FUNCTION FOR P0 AND PA
GPIO_PORTA_PCTL_R =(GPIO_PORTA_PCTL_R&0xFFFFFF00)+0x11;//zero dro first 8 bits
GPIO_PORTA_DEN_R |=0X03;	//enable digital
GPIO_PORTA_AMSEL_R &=~0x03;//enable analog
	
}

int UART0_available(void){

	return ((UART0_FR_R & 0x0010) !=0)?0:1;
}
char UART0_Read(void){
while((UART0_FR_R & 0x0010)!=0);//tool ma el buffer empty msh ha2ra 7aga
return (char)(UART0_DR_R & 0xFF); // awel 8 bits mn el data bta3ty
}

void UART0_write(char data){
while((UART0_FR_R &0x20)!=0);//law hwa full msh ha3mel 7aga
UART0_DR_R=data;
	
}

void read_writeToUpper(void){
char in;
char out;
	
while(1){
in =UART0_Read();//lower case char
out=in-32;//upper case
	
UART0_write(out);	
	
}
}

void PortC_init(void)
{	
	SYSCTL_RCGCGPIO_R |= 0x00000003; //portC activated
	while( (SYSCTL_RCGCGPIO_R & 0x03)==0 ) {};   
	GPIO_PORTC_DIR_R = 0X00; //input 
	GPIO_PORTC_DEN_R = 0XFF;  //enable digital
	GPIO_PORTC_DATA_R=0x00; 
		
}

void PortD_init(void)
{	
	SYSCTL_RCGCGPIO_R |= 0x00000010; //portD activated
	while( (SYSCTL_RCGCGPIO_R & 0x10)==0 ) {};   
	GPIO_PORTF_DIR_R = 0X00 ; //input 
	GPIO_PORTF_DEN_R = 0XFF;  //enable digital
	GPIO_PORTF_DATA_R=0x00; 
		
}
void init_PORTF(void)
{	
SYSCTL_RCGCGPIO_R |= 0x00000020; //enabled
while( (SYSCTL_RCGCGPIO_R & 0x20)==0 );   
GPIO_PORTF_DIR_R = 0X0E ;//F1,F2,F3
GPIO_PORTF_DEN_R = 0X0E; //Digital is enabled
GPIO_PORTF_LOCK_R = 0x4C4F434B;//UNLOCKED
GPIO_PORTF_DATA_R=0x00; //Set LEDS to off initially
	
}







