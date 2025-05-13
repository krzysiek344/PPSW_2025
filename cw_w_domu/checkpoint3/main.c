#include "konwersje.h"
#include "dekod.h"


char test[] = " load 86609 tralala  ";
char test1[] = "load 0x76AB reset";

int main(){
	
	DecodeMsg(test);
	DecodeMsg(test1);
	
}
