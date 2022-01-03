#include "Validaciones.h"
#include <iostream>
#include <conio.h>

int Validaciones::validacionEntero(const char* msj) {
    char* dato = new char[10000];
    char c;
    int valor, i = 0, cont = 0;
    printf_s("%s", msj);
    while ((c = _getch()) != 13 || cont == 0) {
        if ((c >= '0' && c <= '9')) {
            printf_s("%c", c);
            *(dato + i++) = c;
            cont++;
        }
    }
    *(dato + i) = '\0';
    valor = atoi(dato);
    return valor;
}