#include <LPC21xx.H>

#define NIBBLE_bm 0xF

enum Result {OK, ERROR};


void UIntToHexStr (unsigned int uiValue, char pcStr[]){
    
    unsigned char ucNibbleCounter;
    unsigned char ucCurrentCharacter;
    
    pcStr[0] = '0';
    pcStr[1] = 'x';
    
    for(ucNibbleCounter = 0; ucNibbleCounter < 4; ucNibbleCounter ++){
        
        ucCurrentCharacter = ((uiValue >> (12 - 4 * ucNibbleCounter)) & NIBBLE_bm);
        
        if(ucCurrentCharacter < 10){
            pcStr[2 + ucNibbleCounter] = ('0' + ucCurrentCharacter);
        }
        else{
            pcStr[2 + ucNibbleCounter] = ('A' + (ucCurrentCharacter-10));
        }
    }
    pcStr[6] = '\0';
}


enum Result eHexStringToUInt(char pcStr[],unsigned int *puiValue){
    
    unsigned char uucCurrentCharacter;
    unsigned char ucCurrentCharacter;
    //zapytac sie goscia czy ma byc sprawdzenie czy wskazniki sa zerowe
	/*
    if(!puiValue || !pcStr){
        return ERROR;
    }*/
		
    if('0' != pcStr[0] || 'x' != pcStr[1] || '\0' == pcStr[2]){
        return ERROR;
    }
     
    *puiValue = 0;
     
    for(ucCurrentCharacter = 2; ucCurrentCharacter <= 6; ucCurrentCharacter ++){
        
        if('\0' == pcStr[ucCurrentCharacter]){
            return OK;
        }
        
        ucCurrentCharacter = pcStr[ucCurrentCharacter];
        
        if(('0' <= ucCurrentCharacter) && ('9' >= ucCurrentCharacter)){
            ucCurrentCharacter = ucCurrentCharacter - '0';
        }
        else if(('A' <= ucCurrentCharacter) && ('F' >= ucCurrentCharacter)){
            ucCurrentCharacter = ucCurrentCharacter -'A'+10;
        }
        else{
            return ERROR;
        }
				*puiValue <<= 4;
        *puiValue |= ucCurrentCharacter;
    }
    return ERROR;
}


void AppendUIntToString (unsigned int uiValue, char pcDestinationStr[]){
    
    unsigned char uucCurrentCharacter;
    
    for(uucCurrentCharacter = 0; '\0' != pcDestinationStr[uucCurrentCharacter]; uucCurrentCharacter ++){}
    UIntToHexStr(uiValue, &pcDestinationStr[uucCurrentCharacter]);
}


int main(){
	
}
