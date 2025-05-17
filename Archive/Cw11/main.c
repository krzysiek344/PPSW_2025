#include "string.h"
#include "command_decoder.h"

#include "led.h"
#include "servo.h"
#include "uart.h"


int main(){

	char cStringReciever[RECIEVER_SIZE];
	

	LedInit();
	ServoInit(100);
	UART_InitWithInt(9600);
	InitReciever();

	
	while(1){
	
		if (eReciever_GetStatus() == READY) {
			Reciever_GetStringCopy(cStringReciever);  // odbierz wiadomosc
			DecodeMsg(cStringReciever);               // przetwórz ja na tokeny

			if (ucTokenNr == 0) continue;

			// sprawdzamy typ pierwszego tokena
			if (asToken[0].eType == KEYWORD) {
				switch (asToken[0].uValue.eKeyword) {
					case CALLIB:
						ServoCallib();
						break;

					case GOTO:
						if (ucTokenNr >= 2 && asToken[1].eType == NUMBER) {
							ServoGoTo(asToken[1].uValue.uiNumber);
						}
						break;

					default:
						break;
				}
			}
		}
	}
}

