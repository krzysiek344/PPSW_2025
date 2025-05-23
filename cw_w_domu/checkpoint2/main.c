 
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
     
    unsigned char ucCharacterCounter; 
    unsigned char ucCurrentCharacter; 
   
    if(('0' != pcStr[0]) || ('x' != pcStr[1]) || ('\0' == pcStr[2])){ 
        return ERROR; 
    } 
   
    *puiValue = 0; 
      
		for(ucCharacterCounter = 2; '\0' != pcStr[ucCharacterCounter]; ucCharacterCounter ++){  
        
				if(6 <= ucCharacterCounter){
						return ERROR;
				}
			
        ucCurrentCharacter = pcStr[ucCharacterCounter]; 
         
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
    return OK; 
} 
 
 
void AppendUIntToString (unsigned int uiValue, char pcDestinationStr[]){ 
     
    unsigned char ucCharacterCounter; 
     
    for(ucCharacterCounter = 0; '\0' != pcDestinationStr[ucCharacterCounter]; ucCharacterCounter ++){} 
    UIntToHexStr(uiValue, &pcDestinationStr[ucCharacterCounter]); 
}



int main(){
	
		enum Result eResult;
		unsigned int uiValue;
	
		char hex1[] = "0xA";
		char hex2[] = "0xBC3F";
		char hex3[] = "0xFF1FF";
		char hex4[] = "TrallaLala";
		char hex5[] = "0x";
	
	
		eResult = eHexStringToUInt(hex1, &uiValue);
		eResult = eHexStringToUInt(hex2, &uiValue);
		eResult = eHexStringToUInt(hex3, &uiValue);
		eResult = eHexStringToUInt(hex4, &uiValue);
		eResult = eHexStringToUInt(hex5, &uiValue);
		
}

