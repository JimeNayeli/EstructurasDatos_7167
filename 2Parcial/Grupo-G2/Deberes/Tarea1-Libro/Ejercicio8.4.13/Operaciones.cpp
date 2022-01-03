#include <iostream>
#include "Operaciones.h"

template<typename T>
void Operaciones<T>::ordenamiento(T* a, int n) {
    int salto, i, j, k;
    salto = n / 2;

    while (salto > 0) {
        for (i = salto; i < n; i++) {
            j = i - salto;
            while (j >= 0) {
                k = j + salto;
                if (*(a+j) <= *(a+k)) {
                    j = -1;
                }
                else {
                    intercambio(*(a+j), *(a+k));
                    j = j - salto;
                }
            }
        }
        salto = salto / 2;
    }
}

template<typename T>
void Operaciones<T>::intercambio(T& x, T& y) {
    float aux;

    aux = x;
    x = y;
    y = aux;
}

template<typename T>
void Operaciones<T>::ingresoDatos(T* arreglo, int tamanio) {
    for (int i = 0; i < tamanio; i++) {
        std::cout << "Ingrese el dato " << i + 1 << ": "; std::cin >> *(arreglo + i);
    }
}

template<typename T>
void Operaciones<T>::ordenamientoClase(Estudiante* estudiantes, int n) {
    int salto, i, j, k;
    salto = n / 2;

    while (salto > 0) {
        for (i = salto; i < n; i++) {
            j = i - salto;
            while (j >= 0) {
                k = j + salto;
                if (estudiantes[j].getMedia() <= estudiantes[k].getMedia()) {
                    j = -1;
                }
                else {
                    intercambio1( estudiantes[j].getMedia(), estudiantes[k].getMedia());
                    j = j - salto;
                }
            }
        }
        salto = salto / 2;
    }
}

template<typename T>
void Operaciones<T>::intercambio1(T x, T y) {
    float aux;

    aux = x;
    x = y;
    y = aux;
}