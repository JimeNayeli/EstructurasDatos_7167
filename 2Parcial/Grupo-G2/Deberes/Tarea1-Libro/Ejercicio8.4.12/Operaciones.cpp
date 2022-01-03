#include <iostream>
#include "Operaciones.h"

template<typename T>
void Operaciones<T>::ordenar(T* vector, int n) {
    int temp;
    for (int i = 0; i < (n - 1); i++)
    {
        for (int j = 0; j < (n - i - 1); j++)
        {
            if (*(vector + j) < *(vector + j + 1))
            {
                temp = *(vector + j);
                *(vector + j) = *(vector + j + 1);
                *(vector + j + 1) = temp;
            }
        }
    }
}

template<typename T>
void Operaciones<T>::ingresar(T* arreglo, int tamanio) {
    for (int i = 0; i < tamanio; i++) {
        std::cout << "Ingrese el dato " << i + 1 << ":"; std::cin >> *(arreglo + i);
    }
}

template<typename T>
void Operaciones<T>::imprimir(T* arreglo, int tamanio) {
    std::cout << "El vector es: " << std::endl;

    for (int i = 0; i < tamanio; i++) {
        std::cout << *(arreglo + i) << std::endl;
    }
}

template<typename T>
void Operaciones<T>::busquedaBinaria(T* arreglo, int tamanio) {
    int inferior, superior, mitad, dato;
    bool bandera = false;

    std::cout << "Ingrese el dato que desea buscar: "; std::cin >> dato;
    inferior = 0;
    superior = tamanio;

    while (inferior <= superior) {
        int mitad = inferior + (superior - inferior) / 2;

        if (*(arreglo+mitad) == dato) {
            bandera = true;
            break;
        }

        if (*(arreglo+mitad) < dato)
            superior = mitad + 1;

        else
            inferior = mitad - 1;
    }

    if (bandera == true) {
        std::cout << "El numero SI se encontro.";
    }
    else {
        std::cout << "El numero NO se encontro.";
    }

}
