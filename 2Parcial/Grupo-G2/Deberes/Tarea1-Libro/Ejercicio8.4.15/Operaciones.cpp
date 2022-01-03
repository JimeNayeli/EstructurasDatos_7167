#include <iostream>
#include "Operaciones.h"

template<typename T>
void Operaciones<T>::ingresarDatos(T* arreglo, int tamanio) {
	std::cout << std::endl;
	for (int i = 0; i < tamanio; i++) {
		std::cout << "Ingrese el dato " << i + 1 << ": "; std::cin >> *(arreglo + i);
	}
}

template<typename T>
void Operaciones<T>::imprimir(T* arreglo, int tamanio) {

	for (int i = 0; i < tamanio; i++) {
		std::cout << *(arreglo + i) << std::endl;
	}
}

template<typename T>
void Operaciones<T>::ordenar(T* arreglo, int primero, int ultimo) {
	if (primero < ultimo) {
		int indiceP = particion(arreglo, primero, ultimo);
		ordenar(arreglo, primero, indiceP - 1);
		ordenar(arreglo, indiceP + 1, ultimo);
	}
}

template<typename T>
T Operaciones<T>::particion(T* arreglo, int primero, int ultimo) {
	int pivote = *(arreglo + ultimo);
	int i = primero - 1;

	for (int j = primero; j <= ultimo-1; j++) {
		if (*(arreglo + j) <= pivote) {
			i++;
			intercambio(*(arreglo + i), *(arreglo + j));
		}
	}
	intercambio(*(arreglo + i + 1), *(arreglo + ultimo));
	return (i + 1);
}

template<typename T>
void Operaciones<T>::intercambio(T& x, T& y) {
	float aux;

	aux = x;
	x = y;
	y = aux;
}

template<typename T>
void Operaciones<T>::eliminar(T* arreglo, T* aux, T* final, int tamanio) {
	int cont, num,n,i,j=0,z=0,k;
	for (int i = 0; i < tamanio; i++) {
		cont = 0;
		num = *(arreglo + i);
		*(aux + j) = num;
		j++;
		for (int k = 0; k < tamanio; k++) {
			if (*(aux + k) == num) {
				cont++;
			}
		}
		if (cont == 1) {
			*(final + z) = num;
			z++;
		}

	}
	std::cout << std::endl;
	std::cout << "El vector sin elementos repetidos es: " << std::endl;
	for (i = 0; i < z; i++) {
		std::cout << *(final + i) << std::endl;
	}
}