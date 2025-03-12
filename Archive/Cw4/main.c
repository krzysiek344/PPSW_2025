#include <LPC21xx.H>

void Delay(unsigned int czas){
	
	unsigned int uiLicznik;
	
	for(uiLicznik = 0; uiLicznik < czas; uiLicznik ++){
		
		unsigned int uiLicznikCykli = 0;
	
		for(uiLicznikCykli = 0; uiLicznikCykli < 7496; uiLicznikCykli ++){}
		}
	}	
	
int main(){
	
	IO1DIR = (1 << 16);
	
	while(1){
		
		IO1SET = (1 << 16);
		Delay(1000);
		IO1CLR = (1 << 16);
		Delay(1000);
	}
}
