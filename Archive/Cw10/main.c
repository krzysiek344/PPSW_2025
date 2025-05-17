
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
		
		case '\n':
			ServoCallib();
			break;
			
	  case '\r':
			ServoGoTo(12);
			break;
		
	  case '\0':
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
