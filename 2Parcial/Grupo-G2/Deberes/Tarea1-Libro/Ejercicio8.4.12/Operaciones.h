#pragma once

template<typename T>
class Operaciones {
public:
	void ordenar(T* arreglo, int tamanio); //Bubble sort
	void ingresar(T* arreglo, int tamanio);
	void imprimir(T* arreglo, int tamanio);
	void busquedaBinaria(T* arreglo, int tamanio);
};