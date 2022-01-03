#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

int validarNumeroImpar(int);
void ingresar(vector<int>&, int);
void mostrar(vector<int>&);
void ordenar(vector<int>&);
/***********************************************************************
 * Universidad de las Fuerzas Armadas ESPE
 * Autor:Sebastian Bolanios, Ariel Gonzalez, Jimena Tutillo
 * Fecha de creacion: 29/12/2021
 * Fecha de modificacion: 29/12/2021
 * NRC: 7167
 * Nombre de la materia: Estructura de Datos
 ***********************************************************************/
int calcularMediana(vector<int>&);

int main(){
    vector<int> numeros;
    int numero;

    cout << "Ingrese el numero de elementos del vector, (Numero Impar): ";
    cin >> numero;

    numero = validarNumeroImpar(numero);

    ingresar(numeros, numero);
    ordenar(numeros);
    mostrar(numeros);

    cout << "La mediana del vector es: " << calcularMediana(numeros) << endl;

    
    return 0;
}
int validarNumeroImpar(int numero){
    if(numero % 2 == 0){
        cout << "El numero debe ser impar" << endl;
        exit(1);
        return 0;
    }
    else{
        return numero;
    }
}
void ingresar(vector<int>& numeros, int numero){
    srand(time(NULL));
    for(int i=0; i<numero; i++){
        //numeros aleatorios
        numeros.push_back(rand()%100);
    }
}
void mostrar(vector<int>& numeros){
    for(int i=0; i<numeros.size(); i++){
        cout << numeros[i] << " ";
    }
    cout << endl;
}
void ordenar(vector<int>& numeros){
    int i, j;
    int aux;
    for(i=0; i<numeros.size()-1; i++){
        for(j=i+1; j<numeros.size(); j++){
            if(numeros[i] > numeros[j]){
                aux = numeros[i];
                numeros[i] = numeros[j];
                numeros[j] = aux;
            }
        }
    }
}
int calcularMediana(vector<int>& numeros){
    int mediana;
    int tamano = numeros.size();
    if(tamano % 2 == 0){
        mediana = (numeros[tamano/2] + numeros[(tamano/2)-1])/2;
    }
    else{
        mediana = numeros[tamano/2];
    }
    return mediana;
}
