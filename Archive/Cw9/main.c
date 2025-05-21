
#include "servo.h"
#include "keyboard.h"

int main (){

//*****************************************************************
//
// JAK COS TEGO NIE ODDAWAJCIE DOKLADNIE W TAKIEJ FORMIE, 
// NORMALNIE TAKIE COS JAK W LINI 16 I 17  NIE BEDZIE DZIALAC I WAM BEDZIE KAZAL 
// TO NAPRAWIC, 
//
//*****************************************************************
		ServoInit(10);
	
	 ServoGoTo(24);
	 ServoGoTo(12);
	
		KeyboardInit();
	

		while(1){
				
				switch(eKeyboardRead()){
					
						case BUTTON_0:
								ServoCallib();
								break;
							 	
						case BUTTON_1:
								ServoGoTo(12);
								break;
						
						case BUTTON_2:
								ServoGoTo(24);
								break;
						
						case BUTTON_3:
								ServoGoTo(36);
								break;
						
						default:
								break;
				}
		}
}

