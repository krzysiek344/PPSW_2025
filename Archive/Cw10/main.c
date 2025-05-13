
#include "uart.h"
#include "led.h"
#include "servo.h"

extern char cOdebranyZnak;


int main(){
	
	LedInit();
	ServoInit(100);
	UART_InitWithInt(9600);
	
	while(1){
		
		switch(cOdebranyZnak){ 
		
		case 'c':
			ServoCallib();
			break;
			
	  case '1':
			ServoGoTo(sServo.uiCurrentPosition + 12);
			cOdebranyZnak = '\0';
			break;
		
	  case '2':
			ServoGoTo(24);
			break;
		
	  case '3':
			ServoGoTo(36);	
			break;
			
			
		default:
			break;
		}
	}
}
