//**************************************************************
//Zadania z czesci- GPIO
//**************************************************************

#include <LPC21xx.H>
#define LED0_bm (1 << 16)
#define LED1_bm (1 << 17)
#define LED2_bm (1 << 18)
#define LED3_bm (1 << 19)
#define Sw0_bm  (1 << 4)
#define Sw1_bm  (1 << 6)
#define Sw2_bm  (1 << 5)
#define Sw3_bm  (1 << 7)

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

		IO0DIR= IO0DIR & ~(Sw0_bm | Sw1_bm | Sw2_bm | Sw3_bm);
}

enum KeyboardState eKeyboardRead(void){
		
		if(0 == (Sw0_bm & IO0PIN)){
				return BUTTON_0;
		}
		else if(0 == (Sw1_bm & IO0PIN)){
				return BUTTON_1;
		}
		else if(0 == (Sw2_bm & IO0PIN)){
				return BUTTON_2;
		}
		else if(0 == (Sw3_bm & IO0PIN)){
				return BUTTON_3;
		}
		else{
				return RELASED;
		}
}


void LedStep(enum Direction LedDirection){
	
		static unsigned char ucLedPosition = 0;
	
		if(LEFT == LedDirection){
				ucLedPosition = (ucLedPosition + 1) % 4;
				LedOn(ucLedPosition);
		}
		else if(RIGHT == LedDirection){
				ucLedPosition = (ucLedPosition + 3) % 4;
				LedOn(ucLedPosition);
		}
}

void LedStepLeft(void){

			LedStep(LEFT);
}

void LedStepRight(void){

			LedStep(RIGHT);
}
	
	
	
int main(){
	
		char cBufor = 0;
	
		LedInit();
    KeyboardInit();
	
    while(1){
				/*
				Delay(200);
				switch(eKeyboardRead()){
						
						case BUTTON_1:
								LedStep(RIGHT);
								break;
						
						case BUTTON_2:
								LedStep(LEFT);
								break;
						default:
								break;
				}*/
				switch(eKeyboardRead()){
						
						case(BUTTON_1):
							
								if(0 == cBufor){
										cBufor = 1;
										LedStep(RIGHT);
										Delay(50);
								}
								break;
						
						case(BUTTON_2):
								
								if(0 == cBufor){
										cBufor = 1;
										LedStep(LEFT);
										Delay(50);
								}
								break;
						
						case(RELASED):
								cBufor = 0;
								break;
						
						default:
								break;
				}
					
			}
}
	
