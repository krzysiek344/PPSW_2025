#include <LPC21xx.H>

#define NIBBLE_bm 0xF

void UIntToHexStr (unsigned int uiValue, char pcStr[]){
    
    char cNibbleCounter;
    char cCurrentCharacter;
    
    pcStr[0] = '0';
    pcStr[1] = 'x';
    
    for(cNibbleCounter = 0; cNibbleCounter < 4; cNibbleCounter ++){
        
        cCurrentCharacter = ((uiValue >> (12 - 4 * cNibbleCounter)) & NIBBLE_bm);
        
        if(cCurrentCharacter < 10){
            pcStr[2 + cNibbleCounter] = ('0' + cCurrentCharacter);
        }
        else{
            pcStr[2 + cNibbleCounter] = ('A' + (cCurrentCharacter-10));
        }
    }
    pcStr[6] = '\0';
}



enum Result {OK, ERROR};

enum Result eHexStringToUInt(char pcStr[],unsigned int *puiValue){
    
    char cCharacterCounter;
    char cCurrentCharacter;
    
    if(!puiValue || !pcStr){
        return ERROR;
    }
		
    if('0' != pcStr[0] || 'x' != pcStr[1] || '\0' == pcStr[2]){
        return ERROR;
    }
     
    *puiValue = 0;
     
    for(cCharacterCounter = 2; cCharacterCounter <= 6; cCharacterCounter ++){
        
        if('\0' == pcStr[cCharacterCounter]){
            return OK;
        }
        
        cCurrentCharacter = pcStr[cCharacterCounter];
        
        if(('0' <= cCurrentCharacter) && ('9' >= cCurrentCharacter)){
            cCurrentCharacter = cCurrentCharacter - '0';
        }
        else if(('A' <= cCurrentCharacter) && ('F' >= cCurrentCharacter)){
            cCurrentCharacter = cCurrentCharacter -'A'+10;
        }
        else{
            return ERROR;
        }
				*puiValue <<= 4;
        *puiValue |= cCurrentCharacter;
				//ewentualnie: *puiValue = ((*puiValue << 4) | cCurrentCharacter);
				//zapytac sie goscia czy ma byc sprawdzenie czy wskazniki sa zerowe
    }
    return ERROR;
}

void AppendUIntToString (unsigned int uiValue, char pcDestinationStr[]){
    
    unsigned char ucCharacterCounter;
    
    for(ucCharacterCounter = 0; '\0' != pcDestinationStr[ucCharacterCounter]; ucCharacterCounter ++){}
    UIntToHexStr(uiValue, &pcDestinationStr[ucCharacterCounter]);
}


int main(){
	
}
