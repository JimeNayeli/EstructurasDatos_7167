/***********************************************************************
 * Universidad de las Fuerzas Armadas ESPE
 * Autor:Sebastian Bolanios, Ariel Gonzalez, Jimena Tutillo
 * Fecha de creacion: 29/12/2021
 * Fecha de modificacion: 29/12/2021
 * NRC: 7167
 * Nombre de la materia: Estructura de Datos
 ***********************************************************************/
#include <iostream>
using namespace std;
 
int search(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}
	
int main(void)
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
   
    // Function call
    int result = search(arr, n, x);
    (result == -1)
        ? cout << "El elemento no esta presente en el arreglo "
        : cout << "El elemento esta presente en la posicion:  " << result;
    return 0;
}
