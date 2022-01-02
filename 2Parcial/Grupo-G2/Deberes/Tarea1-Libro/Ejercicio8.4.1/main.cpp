#include <iostream>
#include <random>
#include "Operacion.h"
#include "Vector.h"
#include "Auxiliar.h"
/***********************************************************************
 * Universidad de las Fuerzas Armadas ESPE
 * Autor:Sebastian Bolanios, Ariel Gonzalez, Jimena Tutillo
 * Fecha de creacion: Viernes,Diciembre  29, 2021 5:49:23 PM
 * Fecha de modificacion: Viernes, Diciembre 29, 2021 11:10:23 PM
 * NRC: 7167
 * Nombre de la materia: Estructura de Datos
 * Programa: Ordenamiento

 ***********************************************************************/

int main(int argc, char** argv) {
	Vector<int> vector;
	Operacion<int> op;
	int tam=14;
	int num[]={33,45,67,8,12,32,56,7,9,10,22,45,98,9};
	int *p;
	int opc;
	p=num;
	vector.setVector(op.segmentar(tam));
	op.agregar(vector,p,tam);
	
	do{
		opc=menu();
		switch(opc){
			case 1:{
				system("cls");
				cout<<"\n\tArreglo Ascendente\n";
				op.ordenarL(vector,0,tam-1,[](Vector<int> &vector,int &auxIzq,int &auxDer){	
				if (auxIzq >= auxDer+1)
				 {
					int auxDato = *(vector.getVector() + auxDer);
					*(vector.getVector() + auxDer) = *(vector.getVector() + auxDer);
					*(vector.getVector() + auxDer) = auxDato;
				 }
				});
				op.imprimir(vector,tam,[](int val){
					cout<<val<<endl;
				});
				break;
			}
			case 2:{
				system("cls");
				cout<<"\n\tArreglo Descendente\n";
				op.intercambiarDes(vector,0,tam-1); 
				op.imprimir(vector,tam,[](int val){ 
					cout<<val<<endl;
				});
				break;
			}
			case 0:{
				printf("\nAdios.\n");
				break;
			}
			default:{
				printf("\nOpcion incorrecta.\n");
				break;
			}
		}
	}while(opc!=0);
	return 0;
}