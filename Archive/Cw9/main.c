#include <LPC21xx.H>

#include "led.h"
#include "timer_interrupts.h"
#include "keyboard.h"

#define DETECTOR_bm (1 << 10)

enum DetectorState {INACTIVE, ACTIVE};

enum ServoState {CALLIB, IDLE, IN_PROGRESS};

struct Servo{
	
		enum ServoState eState;
		unsigned int uiCurrentPosition; 
		unsigned int uiDesiredPosition;
};

struct Servo sServo;


void DetectorInit(){
	
		IO0DIR= IO0DIR & (~(DETECTOR_bm));
}

enum DetectorState eReadDetector(){
	
		if(0 == (DETECTOR_bm & IO0PIN)){
				return ACTIVE;
		}
		else{
				return INACTIVE;
		}
}

void Automat(){
		
		enum LedState {STATE_STOP, STATE_RIGHT, STATE_LEFT, CALLIB};
		static enum LedState seLedState = CALLIB;

		switch(seLedState){
				
				case CALLIB:
						if(INACTIVE == eReadDetector()){
								LedStepLeft();
								seLedState = CALLIB;
						}
						else{
								seLedState = STATE_STOP;
						}
						break;
				
				case STATE_RIGHT:
						if(BUTTON_1 != eKeyboardRead()){
								LedStepRight();
								seLedState = STATE_RIGHT;
						}
						else{
								seLedState = STATE_STOP;
						}
						break;
								
				case STATE_LEFT:
						if(BUTTON_1 != eKeyboardRead()){
								LedStepLeft();
								seLedState = STATE_LEFT;
						}
						else{
								seLedState = STATE_STOP;
						}
						break;
						
				case STATE_STOP:
						if(BUTTON_0 == eKeyboardRead()){
								seLedState = STATE_LEFT;
						}
						else if(BUTTON_2 == eKeyboardRead()){
								seLedState = STATE_RIGHT;
						}
						else{
								seLedState = STATE_STOP;
						}
						break;
								
				default:
								break;
		}
}


int main (){
	
		unsigned int iMainLoopCtr;
	
		Timer0Interrupts_Init(20000, &Automat);
		LedInit();
		KeyboardInit();
		DetectorInit();

		while(1){
			
				iMainLoopCtr++;
		}
}

