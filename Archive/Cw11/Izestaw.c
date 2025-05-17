
#include "Izestaw.h"

void CopyString(char pcSource[], char pcDestination[]){
	
		unsigned char ucSignCounter;
	
		for(ucSignCounter = 0; '\0' != pcSource[ucSignCounter]; ucSignCounter ++){
				pcDestination[ucSignCounter] = pcSource[ucSignCounter];
		}
		pcDestination[ucSignCounter] = '\0';
}




enum CompResult eCompareString(char pcStr1[], char pcStr2[]){
	
		unsigned char ucSignCounter;
	
		for(ucSignCounter = 0; ('\0' != pcStr1[ucSignCounter]) || ('\0' != pcStr2[ucSignCounter]);ucSignCounter++){
				
				if(pcStr1[ucSignCounter] != pcStr2[ucSignCounter]){
						return DIFFERENT;
				}
		}
		return EQUAL;
}


void AppendString (char pcSourceStr[],char pcDestinationStr[]){
	
		unsigned char ucSignCounter;
	
		for(ucSignCounter = 0; '\0' != pcDestinationStr[ucSignCounter]; ucSignCounter++){}
		CopyString(pcSourceStr, pcDestinationStr + ucSignCounter);
}


void ReplaceCharactersInString(char pcString[],char cOldChar,char cNewChar){
	
		unsigned char ucSignCounter;
	
		for(ucSignCounter = 0; '\0' != pcString[ucSignCounter]; ucSignCounter++){
			
				if(cOldChar == pcString[ucSignCounter]){
						pcString[ucSignCounter] = cNewChar;
				}
		}
}

