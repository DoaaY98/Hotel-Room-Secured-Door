#include "stdint.h"
#include "C:/Keil/EE319Kware/inc/tm4c123gh6pm.h"
#include "Keypad.h"
#include "UART.h"
 //Set LEDS to off GPIO_PORTF_DATA_R=0x00;
  //Set LEDS to on GPIO_PORTF_DATA_R=0x04;
void SystemInit(){}
_Bool correct(char enter[],char correct[]){
int i;
	for( i=0;i<4;i++){
	if (enter[i]!=correct[i]){
	return 0;}
	}
	
	return 1;
}

int main()	
{
init_PORTF();
PortD_init();
PortC_init();
UART_init();
char rooms[5];
	int i;
for ( i=0;i<5;i++){
	rooms[i]=UART0_Read();
}	
char ro_no;
char status;
char set_password[4];


char entered_password[4];



while(1){

ro_no=UART0_Read();
	status =UART0_Read();
	
	
		
		switch (status){
			case 1: //check_in
				
			//check if room is the desired room
				if(ro_no==rooms[1]){
			//set room password
					for(int k=0;k<4;k++){
					set_password[k]=UART0_Read();}
					
					
			//guest enters password
					for(int l=0;l<4;l++){
					entered_password[l]=(char)KeyPad_getPressedKey();
					}
					//compare the password
						if(correct(entered_password,set_password)){
						GPIO_PORTF_DATA_R=0x04;
							//led is on solenoid is open
						}
						else{
						GPIO_PORTF_DATA_R=0x00;}
					// led is off solenoid is closed
					
				}
				else{
					GPIO_PORTF_DATA_R=0x00;
					//no room with this number so solenoid is still closed 
				}
					break;
			case 2:	//Room_service
					if(ro_no==rooms[1]){
				GPIO_PORTF_DATA_R=0x04;
			//open room for room service
						}
					else{
					GPIO_PORTF_DATA_R=0x00;
					//no room with this number so solenoid is still closed 
				}
						
			break;
			
			case 0: //Check_out
				if(ro_no==rooms[1]){
				GPIO_PORTF_DATA_R=0x00;
			//close room forever
					}
					
					
		}
		
		
		
	
}


}