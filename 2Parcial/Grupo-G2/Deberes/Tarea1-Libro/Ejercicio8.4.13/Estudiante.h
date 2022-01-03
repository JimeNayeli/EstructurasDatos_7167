#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>

class Estudiante {
public:
	~Estudiante() {}
	Estudiante();
	Estudiante(std::string nombre, float* notas);
	float calcularMedia(float* notas);
	float getMedia() { return media; }
	void mostrarDatos();

private:
	std::string nombre;
	float* notas;
	float media;
};