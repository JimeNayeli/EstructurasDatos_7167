#pragma once
#include "Estudiante.h"

class Curso {
public:
	~Curso() {}
	Curso();
	Curso(Estudiante* estudiante, int tamanio);
	float calcularMedia(Estudiante* estudiantes, int tamanio);
	float ordenar(Estudiante* estudiantes, int tamanio);

private:
	Estudiante* estudiantes;
	float media;
};