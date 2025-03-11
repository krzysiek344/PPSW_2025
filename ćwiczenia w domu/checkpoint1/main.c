#include <LPC21xx.H>


// sprawdzic kasztan sie nie przyczepi
//      zastanowic sie nad '\n'





//mozna lepiej ale wedlog instrukcji
//-------------------------------funkcja1
void CopyString(char pcSource[], char pcDestination[]){
	
		unsigned int uiLicznik;
	
		pcDestination[0] = pcSource[0];
		for(uiLicznik = 0; '\0' !=  pcSource[uiLicznik]; uiLicznik++){
				pcDestination[uiLicznik + 1] = pcSource[uiLicznik + 1];
		}
}
 
		
		





//git
//--------------------------------funkcja2
enum CompResult { DIFFERENT , EQUAL };

enum CompResult eCompareString(char pcStr1[], char pcStr2[]){
		
		while (*pcStr1 == *pcStr2) {			
        if ('\0' == *pcStr1){
						return EQUAL;
				}
        pcStr1++;
        pcStr2++;
    }
    return DIFFERENT;
}


//----------------------------------funkcja3
/*
void AppendString (char pcSourceStr[],char pcDestinationStr[]){
	
		unsigned int uiLicznik = 0;
	
		for(uiLicznik = 0; pcDestinationStr[uiLicznik] != '\0'; uiLicznik ++){}
		CopyString(pcSourceStr, &pcDestinationStr[uiLicznik]);
}
*/
void AppendString (char pcSourceStr[],char pcDestinationStr[]){
	
		while('\0' != *pcDestinationStr){pcDestinationStr ++;}
		CopyString(pcSourceStr, pcDestinationStr);
}





//git
//-----------------------------------funkcjia4
void ReplaceCharactersInString(char pcString[], char cOldChar, char cNewChar){
	
		while('\0' != *pcString){
				if(*pcString == cOldChar){
						*pcString = cNewChar;
				}
				pcString++;		
		}	
}
//-------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------


void UIntToHexStr (unsigned int uiValue, char pcStr[]){
    
    char cLicznik;
    char cBufor;
    
    pcStr[0] = '0';
    pcStr[1] = 'x';
    
    for(cLicznik = 0; cLicznik < 4; cLicznik ++){
        
        cBufor = (((uiValue >> (12 - 4 * cLicznik))) & 0xF);
        
        if(cBufor < 10){
            pcStr[2 + cLicznik] = ('0' + cBufor);
        }
        else{
            pcStr[2 + cLicznik] = ('A' + (cBufor-10));
        }
    }
    pcStr[6] = '\0';
}




enum Result{ OK, ERROR };

enum Result eHexStringToUInt(char pcStr[],unsigned int *puiValue){
    
    char          cDlugoscCiagu;
    char          cBufor;
    unsigned int  uiPrzeliczenie = 0;
    
    if(!puiValue || !pcStr) {return ERROR;}
    if('0' != pcStr[0] || 'x' != pcStr[1] || '\0' == pcStr[2]) {return ERROR;}
    
    /*
    while('\0' != pcStr[cLicznik]){
        
        if(6 <= cLicznik) {return ERROR;}
        cLicznik ++;
    }*/
    
    for(cDlugoscCiagu = 2; '\0' != pcStr[cDlugoscCiagu]; cDlugoscCiagu ++){
        
        if(6 <= cDlugoscCiagu) {return ERROR;}
        
        cBufor = pcStr[cDlugoscCiagu];
        
        if('0' <= cBufor && '9' >= cBufor){
            uiPrzeliczenie = (uiPrzeliczenie << 4) | (cBufor - 48);
        }
        else if('A' <= cBufor && 'F' >= cBufor){
            uiPrzeliczenie = (uiPrzeliczenie << 4) | (cBufor - 55);
        }
        else{
            return ERROR;
        }
    }
    
    *puiValue = uiPrzeliczenie;
    return OK;
}











int main(){
	
}
