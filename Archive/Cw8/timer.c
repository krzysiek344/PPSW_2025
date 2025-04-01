#include <LPC21xx.H>
#include "timer.h"

#define COUNTER0_ENABLE_bm (1 << 0)
#define COUNTER0_RESET_bm  (1 << 1)

#define RESET_ON_MR0_bm       (1 << 1)
#define INTERRUPT_ON_MR0_bm   (1 << 0)
#define MR0_INTERRUPT_FLAG_bm (1 << 0)

void InitTimer0(void){

		T0TCR = COUNTER0_ENABLE_bm; 
}

void WaitOnTimer0(unsigned int uiTime){
		
		T0TCR |= COUNTER0_RESET_bm;
		T0TCR &= (~COUNTER0_RESET_bm);
	
		while((uiTime * 15) >= T0TC){}
}

void InitTimer0Match0(unsigned int iDelayTime){
	
		T0MR0 = (iDelayTime * 15);
		T0MCR |= (RESET_ON_MR0_bm | INTERRUPT_ON_MR0_bm);
		
		T0TCR |= COUNTER0_RESET_bm;
		T0TCR &= ~(COUNTER0_RESET_bm);
		T0TCR |= COUNTER0_ENABLE_bm;
}

void WaitOnTimer0Match0(void){
	
		while(0 == (T0IR & MR0_INTERRUPT_FLAG_bm)){}
		T0IR = 	MR0_INTERRUPT_FLAG_bm;
}

