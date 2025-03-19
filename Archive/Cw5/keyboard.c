#include <LPC21xx.H>

#define S0_bm  (1 << 4)
#define S1_bm  (1 << 6)
#define S2_bm  (1 << 5)
#define S3_bm  (1 << 7)

enum KeyboardState {RELASED, BUTTON_0, BUTTON_1, BUTTON_2, BUTTON_3};

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