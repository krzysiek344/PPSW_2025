#include "led.h"
#include "keyboard.h"


void Delay(unsigned int czas){
	
		unsigned int uiLicznikCykli1;
		unsigned int uiLicznikCykli2;
		unsigned int uiCzas1ms = 7496;
	
		for(uiLicznikCykli1 = 0; uiLicznikCykli1 < czas; uiLicznikCykli1 ++){
				for(uiLicznikCykli2 = 0; uiLicznikCykli2 < uiCzas1ms; uiLicznikCykli2 ++){}
		}
}

int main(){
	
		enum LedState{STATE_STOP, STATE_RIGHT, STATE_LEFT, STATE_WIPER};
		enum LedState eLedState = STATE_RIGHT;

		unsigned char ucWiperCounter = 0;

		LedInit();
		KeyboardInit();

		while(1){
				
				Delay(100);
				
				switch(eLedState){
					
						case STATE_RIGHT:
								if(eKeyboardRead() == BUTTON_1){
										eLedState = STATE_STOP;
								}
								else{
										LedStepRight();
										eLedState = STATE_RIGHT;
								}
								break;								
								
						case STATE_LEFT:
								if(eKeyboardRead() == BUTTON_1){
										eLedState = STATE_STOP;
								}
								else if(eKeyboardRead() == BUTTON_3){
									
										eLedState = STATE_WIPER;
										ucWiperCounter = 0;
								}
								else{
										LedStepLeft();
										eLedState = STATE_LEFT;
								}
								break;
						
						case STATE_STOP:
								if(eKeyboardRead() == BUTTON_0){
										eLedState = STATE_LEFT;
								}
								else if(eKeyboardRead() == BUTTON_2){
										eLedState = STATE_RIGHT;
								}
								else{
										eLedState = STATE_STOP;
								}
								break;
								
						case STATE_WIPER:
								if(ucWiperCounter == 4){
									
										eLedState = STATE_RIGHT;
								}
								else{
		
										if((ucWiperCounter % 2) == 0){
												LedStepRight();
										}
										else{
												LedStepLeft();
										}
										ucWiperCounter ++;
										eLedState = STATE_WIPER;
								}
								break;
								
						default:
								break;
						
				}
		}
}		
		
				//ZADANIE 3
				/*
				Delay(300);
			
				switch(eLedState){
					
						case STATE_LEFT:
								LedStepLeft();
								ucCounter++;
								
								if(3 <= ucCounter){
										eLedState = STATE_RIGHT;
								}
								break;
			
						case STATE_RIGHT:
								LedStepRight();
								ucCounter--;
						
								if(0 >= ucCounter){
										eLedState = STATE_LEFT;
								}
								break;
				}*/
				//ZADANIE 4 
				/*
				Delay(100);
				
				switch(eLedState){
					
						case STATE_LEFT:
								LedStepLeft();
								ucCounter++;
								
								if(3 <= ucCounter){
										eLedState = STATE_STOP;
								}
								break;
								
						case STATE_STOP:
								if(BUTTON_1 == eKeyboardRead()){
										eLedState = STATE_LEFT;
										ucCounter = 0;
								}
								break;
				}*/
				//ZADANIE 5	
				/*
				Delay(150);
				
				switch(eLedState){
					
						case STATE_RIGHT:
								if(BUTTON_0 != eKeyboardRead()){
										LedStepRight();
								}
								else{
										eLedState = STATE_STOP;
								}
								break;
						
						case STATE_STOP:
								if(BUTTON_1 == eKeyboardRead()){
										eLedState = STATE_RIGHT;
								}
								break;
								
						default:
								break;
				}*/

