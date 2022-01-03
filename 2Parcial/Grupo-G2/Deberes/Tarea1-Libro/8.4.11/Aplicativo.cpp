/***********************************************************************
 * Universidad de las Fuerzas Armadas ESPE
 * Autor:Sebastian Bolanios, Ariel Gonzalez, Jimena Tutillo
 * Fecha de creacion: 29/12/2021
 * Fecha de modificacion: 29/12/2021
 * NRC: 7167
 * Nombre de la materia: Estructura de Datos
 ***********************************************************************/
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

void ingresarNombres(vector<string>& nombres, int numero);
void mostrar(vector<string>& nombres);
void ordenar(vector<string>& nombres);


int main(){
    vector<string> nombres;
    int numero;

    cout << "Ingrese el numero de elementos del vector: ";
    cin >> numero;

    ingresarNombres(nombres, numero);
    cout << "Ordenacion de nombres: " << endl;
    ordenar(nombres);
    mostrar(nombres);

    return 0;
}

void ingresarNombres(vector<string>& nombres, int numero){
    for(int i = 0; i < numero; i++){
        string nombre;
        cout << "Ingrese el nombre " << i + 1 << ": ";
        cin >> nombre;
        nombres.push_back(nombre);
    }
}
void mostrar(vector<string>& nombres){
    for(int i = 0; i < nombres.size(); i++){
        cout << nombres[i] << endl;
    }
}

void ordenar(vector<string>& nombres){
    sort(nombres.begin(), nombres.end());
}
