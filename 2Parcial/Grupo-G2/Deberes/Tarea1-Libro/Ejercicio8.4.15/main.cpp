/***********************************************************************
 * Universidad de las Fuerzas Armadas ESPE
 * Autor:Sebastian Bolanios, Ariel Gonzalez, Jimena Tutillo
 * Fecha de creacion: Viernes,Diciembre  29, 2021
 * Fecha de modificacion: Domingo, Enero 02, 2022
 * NRC: 7167
 * Nombre de la materia: Estructura de Datos
 * Programa: Ordenamiento (Quick sort) y eliminacion de elementos repetidos
 ***********************************************************************/

#include <iostream>
#include <stdlib.h>
#include "Operaciones.h"
#include "Operaciones.cpp"
#include "Validaciones.h"

int main() {

	int tamanio;
	Operaciones<int> op;
	Validaciones v;
	tamanio = v.validacionEntero("Ingrese el tamanio del vector que desea ordenar: ");
	int* arreglo = new int[tamanio];
	op.ingresarDatos(arreglo, tamanio);
	int* aux = new int[tamanio];
	int* final = new int[tamanio];

	std::cout << "\nEl vector que ingreso es: " << std::endl;
	op.imprimir(arreglo, tamanio);
	op.ordenar(arreglo, 0, tamanio - 1);
	std::cout << "\nEl vector ordenado es: " << std::endl;
	op.imprimir(arreglo, tamanio);
	op.eliminar(arreglo, aux, final, tamanio);
}