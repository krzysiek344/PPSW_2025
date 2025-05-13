#include <LPC21xx.H>

#include "led.h"
#include "timer_interrupts.h"
#include "servo.h"

#define DETECTOR_bm (1 << 10)

enum DetectorState {INACTIVE, ACTIVE};
enum ServoState {CALLIB, OFFSET, IDLE, IN_PROGRESS};


struct Servo{
	
		enum ServoState eState;
		unsigned int uiCurrentPosition; 
		unsigned int uiDesiredPosition;
};

struct Servo sServo;



void DetectorInit(void){
	
		IO0DIR= IO0DIR & (~(DETECTOR_bm));
}


enum DetectorState eReadDetector(void){
	
		if(0 == (DETECTOR_bm & IO0PIN)){
				return ACTIVE;
		}
		else{
				return INACTIVE;
		}
}


void Automat(void){

		switch(sServo.eState){
				
				case CALLIB:
						if(eReadDetector() == INACTIVE){
								LedStepLeft();
								sServo.eState = CALLIB;
						}
						else{
								sServo.uiCurrentPosition = 0;
								sServo.uiDesiredPosition = 12;
								sServo.eState = OFFSET;
						}
						break;
						
				case OFFSET:
						if(sServo.uiDesiredPosition != sServo.uiCurrentPosition){
								LedStepRight();
								sServo.uiCurrentPosition++;
								sServo.eState = OFFSET;
						}
						else{
								sServo.uiCurrentPosition = 0;
								sServo.uiDesiredPosition = 0;
								sServo.eState = IDLE;
						}
						break;
						
				case IDLE:
						if(sServo.uiCurrentPosition != sServo.uiDesiredPosition){
								sServo.eState = IN_PROGRESS;
						}
						else{
								sServo.eState = IDLE;
						}
						break;
						
				case IN_PROGRESS:
						if(sServo.uiDesiredPosition < sServo.uiCurrentPosition){
							
								LedStepLeft();
								sServo.uiCurrentPosition--;
						  	sServo.eState = IN_PROGRESS;
						}
						else if(sServo.uiDesiredPosition > sServo.uiCurrentPosition){
								
								LedStepRight();
								sServo.uiCurrentPosition++;
								sServo.eState = IN_PROGRESS;
						}
						else{
								sServo.eState = IDLE;
						}
						break;
								
				default:
						break;
		}
}


void ServoInit(unsigned int uiServoFrequency){
	
		LedInit();
		DetectorInit();
	
		Timer0Interrupts_Init((1000000/uiServoFrequency), &Automat);
	
		while(sServo.eState != IDLE){}  //*
}


void ServoCallib(void){
	
		sServo.eState = CALLIB;
}


void ServoGoTo(unsigned int uiPosition){
	
		sServo.uiDesiredPosition = uiPosition;
		while(sServo.uiCurrentPosition != sServo.uiDesiredPosition){}          //*
}
