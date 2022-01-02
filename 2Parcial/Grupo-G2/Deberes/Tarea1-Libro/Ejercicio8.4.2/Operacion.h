
#include "Vector.h"
//#include "Auxiliar.h"
#include <iostream>
#include<functional>//function Una clase que envuelve un objeto invocable
#include <stdlib.h>
using namespace std;
template <typename T>
class Operacion {
public:
	T* segmentar(int);
	void encerar(Vector<T>, int);
	void agregar(Vector<T>, int);
	void imprimir(Vector<T> vector, int size, void(func)(int));
	void ordenarShellSort(Vector<T>, int, function<void(int&, int&)>intercambio);	
};
//indican al compilador que inserte una copia del cuerpo de la funcion
// en cada lugar donde se llama a la funcion.
template<typename T>
inline T* Operacion<T>::segmentar(int tam)
{
	Vector<T> vector;
	vector.set_vector((T*)malloc((tam * sizeof(T))));
	return vector.get_vector();
}
template<typename T>
inline void Operacion<T>::agregar(Vector<T> vector, int tam)
{
	cout<<"\n\tIngrese los numeros:\n ";
	for (int i = 0; i < tam; i++)
	{
		cin>>*(vector.get_vector() + i);
	}
}
template<typename T>
inline void Operacion<T>::encerar(Vector<T> vector, int tam)
{
	for (int i = 0; i < tam; i++)
	{
		*(vector.get_vector() + i) = 0;
	}

}

template<typename T>
void Operacion<T>::ordenarShellSort(Vector<T> vector, int tamanio, function<void(int&, int&)> intercambio)
{
    int i, j, intervalo, temp;
    i = tamanio + 1;
    bool band = false;
    while (i > 1) {
        i = i/2;
        band = true;
        while (band) {
            band = false;
            j = 0;
            while ((j + i) < tamanio) {
                if (*(vector.get_vector() + j) > *(vector.get_vector() + i + j)) {
                    intercambio(*(vector.get_vector() + j), *(vector.get_vector() + i + j));
                    band = true;
                }
                j = j + 1;
            }
        }
    }
}

template<typename T>
void Operacion<T>::imprimir(Vector<T> vector, int tam,void(lambda)(int))
{
	for (int i =0; i<tam; i++)
	{
		lambda(*(vector.get_vector()+i));
	}
}