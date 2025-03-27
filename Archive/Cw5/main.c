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
	
		LedInit();
		KeyboardInit();
	
		while(1){
			
				switch(eKeyboardRead()){
		
						case BUTTON_1:
								LedStepRight();
								break;

						case BUTTON_2:
								LedStepLeft();
								break;

						default:
								break;

				}
				Delay(100);
		}
}
