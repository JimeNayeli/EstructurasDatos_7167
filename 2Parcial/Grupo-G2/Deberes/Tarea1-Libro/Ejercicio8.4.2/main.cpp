#include <iostream>
#include "Operacion.h"
#include "Vector.h"
#include "Busqueda.h"
#include "Auxiliar.h"
/***********************************************************************
 * Universidad de las Fuerzas Armadas ESPE
 * Autor:Sebastian Bolanios, Ariel Gonzalez, Jimena Tutillo
 * Fecha de creacion: Viernes,Diciembre  29, 2021 5:49:23 PM
 * Fecha de modificacion: Viernes, Diciembre 29, 2021 11:10:23 PM
 * NRC: 7167
 * Nombre de la materia: Estructura de Datos
 * Programa: Busqueda numeros

 ***********************************************************************/
int main(int argc, char** argv) {
	char mensaje[]="\n\tDesea volver a realizar? S/N: ";
	char mensaje2[]="\n\tDesea volver a buscar? S/N: ";
	Vector<int> vector;
	Operacion<int> op;
	int buscar,tam=5;
	vector.set_vector(op.segmentar(tam));
	op.agregar(vector,tam);
	do{
		system("cls");
		op.imprimir(vector, tam, [](int value) {
			cout<< value <<"\n";
		});
		cout << "ordenado" << endl;
		op.ordenarShellSort(vector, tam,[](int& val1,int&val2){
			int aux=val2;
			val2=val1;
			val1=aux;
			
		});
		op.imprimir(vector, tam, [](int val) {
			cout << val<<"\n";
		});
		
		do{
			cout<<"\nIngrese numero a buscar: ";
			cin>>buscar;
			busquedaSecuencial(vector,tam,buscar);
		}while(continuar(mensaje2));
	}while(continuar(mensaje));
	return 0;
}