#pragma once

template<typename T>
class Operaciones {
public:
	void ingresarDatos(T* arreglo, int tamanio);
	void ordenar(T* arreglo, int primero, int ultimo); //Quick sort
	void eliminar(T* arreglo,T* aux, T* final, int tamanio);
	void imprimir(T* arreglo, int tamanio);
	void intercambio(T& x, T& y);
	T particion(T* arreglo, int primero, int ultimo);
};