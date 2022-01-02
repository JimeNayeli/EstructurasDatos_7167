
#include <ctype.h>

bool continuar(char mensaje[]){
	char ch;
	printf(mensaje);
	do{
		scanf("%c",&ch);
		ch = toupper(ch);		
	}while(ch!='S'&&ch!='N');
	return (ch=='S'?true:false);
}
