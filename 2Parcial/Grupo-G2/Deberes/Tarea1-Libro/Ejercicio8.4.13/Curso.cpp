#include "Curso.h"

Curso::Curso() {
	this->estudiantes = new Estudiante[0];
	this->media = 0;
}

Curso::Curso(Estudiante* estudiantes, int tamanio) {
	this->estudiantes = estudiantes;
	this->media = calcularMedia(estudiantes, tamanio);
}

float Curso::calcularMedia(Estudiante* estudiantes, int tamanio) {
	float media = 0, suma = 0;
	for (int i = 0; i < tamanio; i++) {
		suma = suma + (*(estudiantes + i)).getMedia();
	}
	media = suma / tamanio;
	return media;
}