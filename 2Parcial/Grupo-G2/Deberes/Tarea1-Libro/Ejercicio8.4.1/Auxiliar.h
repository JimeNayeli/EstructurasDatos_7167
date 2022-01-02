#include <iostream>
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

int menu()
{
	int opc;
	printf("\n**** INICIO ****");
	printf("\n1. Ordenar Ascendente");
	printf("\n2. Ordenar Descendente");
	printf("\n0. Salir");
	printf("\nElija una opcion: ");
	scanf("%d",&opc);
	return opc;
}