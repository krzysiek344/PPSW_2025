#include <LPC21xx.H>

int iLoopCtr;
int iPlusCounter;
int iMinusCounter;
int main()
{
iPlusCounter=10;
iMinusCounter = 10;
for (iLoopCtr=0 ; iLoopCtr<5; iLoopCtr++){
		iPlusCounter=iPlusCounter+3;
		iMinusCounter=iMinusCounter-3;
		}
}

//----cwiczenie_praca_z_rejestrami
// 1000 0000 0011 0000 0000 0000 1110 1000
//  8 |  0  | 3  | 0  | 0  | 0  | E   | 8

//INT = 0x803000E8;
