//**************************************************************
//Zadania z czesci- GPIO
//**************************************************************

#include <LPC21xx.H>

#define LED0_bm (1 << 16)
#define LED1_bm (1 << 17)
#define LED2_bm (1 << 18)
#define LED3_bm (1 << 19)

#define S0_bm  (1 << 4)
#define S1_bm  (1 << 6)
#define S2_bm  (1 << 5)
#define S3_bm  (1 << 7)

enum KeyboardState {RELASED, BUTTON_0, BUTTON_1, BUTTON_2, BUTTON_3};
enum Direction {LEFT, RIGHT};


void Delay(unsigned int czas){
	
		unsigned int uiLicznikCykli1;
		unsigned int uiLicznikCykli2;
		unsigned int uiCzas1ms = 7496;
	
		for(uiLicznikCykli1 = 0; uiLicznikCykli1 < czas; uiLicznikCykli1 ++){
				for(uiLicznikCykli2 = 0; uiLicznikCykli2 < uiCzas1ms; uiLicznikCykli2 ++){}
		}
	}

void LedInit(void){
		
		IO1DIR= (IO1DIR | LED0_bm | LED1_bm | LED2_bm | LED3_bm);
	
		IO1CLR= (LED1_bm | LED2_bm | LED3_bm);
		IO1SET= LED0_bm;
}	

void LedOn(unsigned char ucLedIndeks){
	
		IO1CLR= (LED0_bm | LED1_bm | LED2_bm | LED3_bm);
	
		switch(ucLedIndeks){
				
				case(0):
						IO1SET= LED0_bm;
						break;
				
				case(1):
						IO1SET= LED1_bm;
						break;
				
				case(2):
						IO1SET= LED2_bm;
						break;
				
				case(3):
						IO1SET= LED3_bm;
						break;
				
				default:
						break;
		}
}

void KeyboardInit(void){

		IO0DIR= IO0DIR & ~(S0_bm | S1_bm | S2_bm | S3_bm);
}

enum KeyboardState eKeyboardRead(void){
		
		if(0 == (S0_bm & IO0PIN)){
				return BUTTON_0;
		}
		else if(0 == (S1_bm & IO0PIN)){ //                                  niewcisniete   0x40    wcisniete- 0x0
				return BUTTON_1;
		}
		else if(0 == (S2_bm & IO0PIN)){ //																	niewcisniete   0x20    wcisniete- 0x0
				return BUTTON_2;
		}
		else if(0 == (S3_bm & IO0PIN)){
				return BUTTON_3;
		}
		else{
				return RELASED;
		}
}

void LedStep(enum Direction LedDirection){
	
		static unsigned char ucLedPosition = 0;
	
		if(LEFT == LedDirection){
			
				ucLedPosition = (ucLedPosition + 1);
		}
		else if(RIGHT == LedDirection){
			
				ucLedPosition = (ucLedPosition - 1);
		}
		
		ucLedPosition = ucLedPosition % 4;
		LedOn(ucLedPosition);
}

void LedStepLeft(void){

			LedStep(LEFT);
}

void LedStepRight(void){

			LedStep(RIGHT);
}
	
	
	
int main(){
	
		LedInit();
    KeyboardInit();
	
    while(1){
				
				Delay(150);
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
		}
}
	
