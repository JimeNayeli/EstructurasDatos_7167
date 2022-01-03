/***********************************************************************
 * Universidad de las Fuerzas Armadas ESPE
 * Autor:Sebastian Bolanios, Ariel Gonzalez, Jimena Tutillo
 * Fecha de creacion: Viernes,Diciembre  29, 2021 
 * Fecha de modificacion: Domingo, Enero 02, 2022 
 * NRC: 7167
 * Nombre de la materia: Estructura de Datos
 * Programa: Ordenamiento y Busqueda binaria
 ***********************************************************************/

#include <iostream>
#include <stdlib.h>
#include "Validaciones.h"
#include "Operaciones.h"
#include "Operaciones.cpp"

using std::cout;
using std::cin;

int main() {
	Validaciones v;
	Operaciones<int> operacion;
	int tamanio, * arreglo, op;
	tamanio = v.validacionEntero("Ingrese el tamanio del vector que desea ordenar: ");

	arreglo = new int[tamanio];
	cout << std::endl;
	operacion.ingresar(arreglo, tamanio);

	operacion.imprimir(arreglo, tamanio);
	operacion.ordenar(arreglo, tamanio);

	cout << "Despues del ordenamiento ";
	operacion.imprimir(arreglo, tamanio);

	do {
		cout << "\n¿Desea realizar busqueda de algun elemento?" << std::endl;
		cout << "1. Si" << std::endl;
		op = v.validacionEntero("2. No\n");
		cout << std::endl;
		switch (op)
		{
		case 1:
			operacion.busquedaBinaria(arreglo, tamanio);
			break;
		case 2:
			cout << "Ha salido del programa.";
			break;
		default:
			cout << "Opcion no valida, intente de nuevo.";
			break;
		}
	} while (op != 2);
}

