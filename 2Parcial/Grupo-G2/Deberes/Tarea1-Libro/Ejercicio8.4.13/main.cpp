#include <iostream>
#include <stdlib.h>
#include <string>
#include "Estudiante.h"
#include "Operaciones.h"
#include "Operaciones.cpp"
#include "Curso.h"

int main() {
	Curso* curso;
	int cantidadEstudiantes;
	float* notas = new float[5];
	float nota1 = 0, nota2 = 0, nota3 = 0, nota4 = 0, nota5 = 0, media = 0;
	float* notasMediasAsignatura = new float[5];
	std::string nombre;
	Operaciones<float> op;

	std::cout << "Ingrese la cantidad de estudiantes que desea en su curso: "; std::cin >> cantidadEstudiantes;
	Estudiante* estudiante = new Estudiante[cantidadEstudiantes];

	for (int i = 0; i < cantidadEstudiantes; i++) {
		std::cout << "\nIngrese el nombre del estudiante " << i + 1 << ": "; std::cin >> nombre;
		op.ingresoDatos(notas, 5);
		estudiante[i] = Estudiante(nombre, notas);
		nota1 = nota1 + notas[0];
		nota2 = nota2 + notas[1];
		nota3 = nota3 + notas[2];
		nota4 = nota4 + notas[3];
		nota5 = nota5 + notas[4];
		op.ordenamiento(notas, 5);
		std::cout << "\nArreglo ordenado" << std::endl;
		for (int j = 0; j < 5; j++) {
			std::cout << *(notas + j) << std::endl;
		}

	}
	nota1 = nota1 / cantidadEstudiantes;
	nota2 = nota2 / cantidadEstudiantes;
	nota3 = nota3 / cantidadEstudiantes;
	nota4 = nota4 / cantidadEstudiantes;
	nota5 = nota5 / cantidadEstudiantes;

	curso=new Curso(estudiante,cantidadEstudiantes);
	media = curso->calcularMedia(estudiante,cantidadEstudiantes);
	std::cout << "\nLa media de la clase " << " es :" << media << std::endl;

	std::cout << "\nLa media de la nota " << 1 << " es :" << nota1 << std::endl;
	std::cout << "La media de la nota " << 2 << " es :" << nota2 << std::endl;
	std::cout << "La media de la nota " << 3 << " es :" << nota3 << std::endl;
	std::cout << "La media de la nota " << 4 << " es :" << nota4 << std::endl;
	std::cout << "La media de la nota " << 5 << " es :" << nota5 << std::endl;
	/*op.ordenamientoClase(estudiante, cantidadEstudiantes);

	std::cout << "ORDENADO";
	for (int i = 0; i < cantidadEstudiantes; i++) {
		estudiante[i].mostrarDatos();
	}*/

}