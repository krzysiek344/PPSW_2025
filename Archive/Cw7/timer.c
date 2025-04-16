#include <LPC21xx.H>
#include "timer.h"

#define COUNTER0_ENABLE_bm (1 << 0)
#define COUNTER0_RESET_bm  (1 << 1)

#define RESET_ON_MR0_bm       (1 << 1)
#define INTERRUPT_ON_MR0_bm   (1 << 0)
#define MR0_INTERRUPT_FLAG_bm (1 << 0)

void InitTimer0(void){

		T0TCR = COUNTER0_ENABLE_bm;				//wlaczenie timera0
}

void WaitOnTimer0(unsigned int uiTime){
		
		T0TCR |= COUNTER0_RESET_bm;				//reset timera0
		T0TCR &= (~COUNTER0_RESET_bm);		//wylaczenie bitu resetujacego timer0
	
		while((uiTime * 15) != T0TC){}
}

void InitTimer0Match0(unsigned int iDelayTime){
	
		T0MR0 = (iDelayTime * 15);			//ustawienie rejestru porownania na wartosc zadana x15
	
		T0MCR |= (RESET_ON_MR0_bm | INTERRUPT_ON_MR0_bm);			//skonfigurowanie ukladu porownujacego tak 
																													//zeby po zrownaniu sie MR oraz TC tak zeby TC zresetowalo 
																													//sie oraz zeby zapalila sie flaga przerwania
		
		T0TCR |= COUNTER0_RESET_bm;				//reset timera0											
		T0TCR &= ~(COUNTER0_RESET_bm);		//wylaczenie bitu resetujacego timer0
		T0TCR |= COUNTER0_ENABLE_bm;			//wlaczenie timera0
}

void WaitOnTimer0Match0(void){
	
		while(0 == (T0IR & MR0_INTERRUPT_FLAG_bm)){}
		T0IR = T0IR |	MR0_INTERRUPT_FLAG_bm;		//reset flagi przerwania wpisujac
}

