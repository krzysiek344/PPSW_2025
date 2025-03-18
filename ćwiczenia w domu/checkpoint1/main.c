#include <LPC21xx.H>


//-----------------------------------------------------------------------------funkcja1
/*
void CopyString(char pcSource[], char pcDestination[]){
	
		unsigned int uiLicznik;
	
		pcDestination[0] = pcSource[0];
		for(uiLicznik = 0; '\0' !=  pcSource[uiLicznik]; uiLicznik++){
				pcDestination[uiLicznik + 1] = pcSource[uiLicznik + 1];
		}
}
*/
void CopyString(char pcSource[], char pcDestination[]){
	
		unsigned char ucSignCounter;
	
		for(ucSignCounter = 0; '\0' != pcSource[ucSignCounter]; ucSignCounter ++){
				pcDestination[ucSignCounter] = pcSource[ucSignCounter];
		}
		pcDestination[ucSignCounter] = '\0';
}

//--------------------------------------------------------------------------------------funkcja2
/*
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
*/

enum CompResult { DIFFERENT , EQUAL };

enum CompResult eCompareString(char pcStr1[], char pcStr2[]){
	
		unsigned char ucSignCounter;
	
		for(ucSignCounter = 0; ('\0' != pcStr1[ucSignCounter]) || ('\0' != pcStr2[ucSignCounter]);ucSignCounter++){
				
				if(pcStr1[ucSignCounter] != pcStr2[ucSignCounter]){
						return DIFFERENT;
				}
		}
		return EQUAL;
}

//-----------------------------------------------------------------------------------------funkcja3
/*
void AppendString (char pcSourceStr[],char pcDestinationStr[]){
	
		while('\0' != *pcDestinationStr){pcDestinationStr ++;}
		CopyString(pcSourceStr, pcDestinationStr);
}
*/

void AppendString (char pcSourceStr[],char pcDestinationStr[]){
	
		unsigned char ucSignCounter;
	
		for(ucSignCounter = 0; '\0' != pcDestinationStr[ucSignCounter]; ucSignCounter++){}
		CopyString(pcSourceStr, pcDestinationStr + ucSignCounter);
}

//-----------------------------------------------------------------------------------------------funkcjia4
/*
void ReplaceCharactersInString(char pcString[], char cOldChar, char cNewChar){
	
		while('\0' != *pcString){
				if(*pcString == cOldChar){
						*pcString = cNewChar;
				}
				pcString++;		
		}	
}
*/

void ReplaceCharactersInString(char pcString[],char cOldChar,char cNewChar){
	
		unsigned char ucSignCounter;
	
		for(ucSignCounter = 0; '\0' != pcString[ucSignCounter]; ucSignCounter++){
			
				if(cOldChar == pcString[ucSignCounter]){
						pcString[ucSignCounter] = cNewChar;
				}
		}
}



int main(){


	
}
