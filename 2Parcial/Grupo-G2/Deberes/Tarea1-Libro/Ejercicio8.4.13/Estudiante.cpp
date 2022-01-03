#include "Estudiante.h"

Estudiante::Estudiante() {
	this->nombre = " ";
	this->notas = new float[0];
	this->media = 0;
}

Estudiante::Estudiante(std::string nombre, float* arreglo) {
	this->nombre = nombre;
	this->notas = arreglo;
	this->media = calcularMedia(this->notas);
}

float Estudiante::calcularMedia(float* notas) {
	int tamanio = 5;
	float media, suma = 0;

	for (int i = 0; i < tamanio; i++) {
		suma = suma + *(notas + i);
	}

	media = suma / tamanio;
	std::cout << "\nLa media del estudiante es: " << media << std::endl;
	return media;
}

void Estudiante::mostrarDatos() {
	std::cout << "Nombre: " << this->nombre;
	std::cout << "Notas: " << std::endl;
	for (int i = 0; i < 5; i++) {
		std::cout << this->notas[i];
	}
	std::cout << "La media es: " << this->media << std::endl;
}