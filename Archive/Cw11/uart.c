#include <LPC210X.H>

#include "uart.h" 
#include "Izestaw.h"

/************ UART ************/
// U0LCR Line Control Register
#define mDIVISOR_LATCH_ACCES_BIT                   0x00000080
#define m8BIT_UART_WORD_LENGTH                     0x00000003

// UxIER Interrupt Enable Register
#define mRX_DATA_AVALIABLE_INTERRUPT_ENABLE        0x00000001
#define mTHRE_INTERRUPT_ENABLE                     0x00000002

// UxIIR Pending Interrupt Identification Register
#define mINTERRUPT_PENDING_IDETIFICATION_BITFIELD  0x0000000F
#define mTHRE_INTERRUPT_PENDING                    0x00000002
#define mRX_DATA_AVALIABLE_INTERRUPT_PENDING       0x00000004    

//PINSEL0 Pin Function Select Register 0 
#define mRxD_on_P01                                (1 << 2)

/************ Interrupts **********/
// VIC (Vector Interrupt Controller) channels
#define VIC_UART0_CHANNEL_NR  6
#define VIC_UART1_CHANNEL_NR  7

// VICVectCntlx Vector Control Registersz
#define mIRQ_SLOT_ENABLE                           0x00000020


//struktura danych IIUART
//#define RECIEVER_SIZE 7

//enum eRecieverStatus {EMPTY, READY, OVERFLOW};

typedef struct RecieverBuffer
{ 
char cData[RECIEVER_SIZE];				//odebrany lancuch znakowy
unsigned char ucCharCtr;					//iterator
enum eRecieverStatus eStatus;			//status bufora
}RecieverBuffer;

////////////// Zmienne globalne ////////////


RecieverBuffer sBuffer;         

char cOdebranyZnak;

//wstawienie znakow do bufora
void Reciever_PutCharacterToBuffer(char cCharacter){

	if((sBuffer.eStatus == READY) || (sBuffer.eStatus == OVERFLOW)){
		return;
	}
	else if((cCharacter == '\r') || (cCharacter == '\n') || (cCharacter == '\0')){
		sBuffer.cData[sBuffer.ucCharCtr] = '\0';
		sBuffer.eStatus = READY;
	}
	else if(sBuffer.ucCharCtr < RECIEVER_SIZE - 1){
		sBuffer.cData[sBuffer.ucCharCtr] = cCharacter;
		sBuffer.ucCharCtr ++;
	}
	else{
		sBuffer.eStatus = OVERFLOW;
	}
}


//odczyt statusu bufora
enum eRecieverStatus eReciever_GetStatus(void){

	return sBuffer.eStatus;
}

void InitReciever(void){

	sBuffer.eStatus = EMPTY;
	sBuffer.ucCharCtr = 0;
}
 
void Reciever_GetStringCopy(char *ucDestination){

	if(sBuffer.eStatus == READY){
		CopyString(sBuffer.cData, ucDestination);
		InitReciever();
	}
}



///////////////////////////////////////////
__irq void UART0_Interrupt (void) {
   
   
   unsigned int uiCopyOfU0IIR=U0IIR; // odczyt U0IIR powoduje jego kasowanie wiec lepiej pracowac na kopii

   if((uiCopyOfU0IIR & mINTERRUPT_PENDING_IDETIFICATION_BITFIELD) == mRX_DATA_AVALIABLE_INTERRUPT_PENDING) // odebrano znak
   {
      cOdebranyZnak = U0RBR;
   } 
	 
   Reciever_PutCharacterToBuffer(cOdebranyZnak);
	 
   if((uiCopyOfU0IIR & mINTERRUPT_PENDING_IDETIFICATION_BITFIELD) == mTHRE_INTERRUPT_PENDING)              // wyslano znak - nadajnik pusty 
   {
	 
      // narazie nic nie wysylamy
   }
	 
   VICVectAddr = 0; // Acknowledge Interrupt
}

//////////////////////////////////////////// 
void UART_InitWithInt(unsigned int uiBaudRate){

   // UART0
   PINSEL0 |= mRxD_on_P01;                        							// ustawic pina na odbiornik uart0
   U0LCR  |= m8BIT_UART_WORD_LENGTH | mDIVISOR_LATCH_ACCES_BIT; // dlugosc slowa, DLAB = 1
   U0DLL   = ((15000000/16)/uiBaudRate);                        // predkosc transmisji
   U0LCR  &= (~mDIVISOR_LATCH_ACCES_BIT);                       // DLAB = 0
	 
	 
   U0IER  |= mRX_DATA_AVALIABLE_INTERRUPT_ENABLE;               // zalaczenie przerwan z lini Rx (UART0)

   // INT
   VICVectAddr2  = (unsigned long) UART0_Interrupt;             // konfiguracja przerwania UART
   VICVectCntl2  = mIRQ_SLOT_ENABLE | VIC_UART0_CHANNEL_NR;     
   VICIntEnable |= (0x1 << VIC_UART0_CHANNEL_NR);              
}






















