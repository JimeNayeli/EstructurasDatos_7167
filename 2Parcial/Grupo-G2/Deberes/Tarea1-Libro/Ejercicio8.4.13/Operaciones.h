#pragma once
#include "Estudiante.h"

template<typename T>
class Operaciones {
public:
	~Operaciones() {}
	void ordenamiento(T* arreglo, int tamanio); //Shell sort
	void ordenamientoClase(Estudiante* estudiantes, int tamanio);
	void intercambio(T& x, T& y);
	void intercambio1(T x, T y);
	void ingresoDatos(T* arreglo, int tamanio);
};