#include "Vector.h"
#include <iostream>
#include <functional>
#include <stdlib.h>

template<typename T>
class Operacion {
	private:
	int auxIzq;
	int auxDer;
	int pivote;
	int auxDato;
public:
	T* segmentar(int);
	void encerar(Vector<T>, int);
	void agregar(Vector<T>,int*,int);
	void intercambiar(Vector<T> vector, int newIzq, int newDer);
	void intercambiarDes(Vector<T> vector, int newIzq, int newDer);
	void ordenar(Vector<T> vector, int izq, int der);
	void imprimir(Vector<T> vector, int size, void(lambda)(int));
	void ordenarL(Vector<T> vector,int izq, int der,function<void(Vector<T> &vector,int&,int&)>lambda);
	};

template<typename T>
inline T* Operacion<T>::segmentar(int tam)
{
	Vector<T> vector;
	vector.setVector((T*)malloc((tam * sizeof(T))));
	return vector.getVector();
}

template<typename T>
inline void Operacion<T>::encerar(Vector<T> vector,int tam)
{
	int counter;
	for (int i = 0; i <tam; i++)
	{
		*(vector.getVector() + i) = 0;
	}

}

template<typename T>
void Operacion<T>::imprimir(Vector<T> vector, int tam,void(lambda)(int))
{
	for (int i =0; i<tam; i++)
	{
		lambda(*(vector.getVector()+i));
	}
}

template<typename T>
inline void Operacion<T>::agregar(Vector<T> vector,int *num,int tam)
{
	for (int i = 0; i <tam; i++)
	{
		*(vector.getVector() + i)=*(num+i);
	}
}

template <typename T>
void Operacion<T>::intercambiar(Vector<T> vector, int newIzq, int newDer) {
 auxIzq = newIzq;
 auxDer = newDer;
 pivote = *(vector.getVector() + ((newIzq + newDer) / 2));
do {
	 while ((*(vector.getVector() + auxIzq) < pivote) && (auxDer <= newDer))
	 {
	 	auxIzq++;
	 }
	 while ((pivote < *(vector.getVector() + auxDer)) && (auxDer > newIzq)){
	 	auxDer--;
	 }
		 if (auxIzq <= auxDer)
		 {
			auxDato = *(vector.getVector() + auxIzq);
			*(vector.getVector() + auxIzq) = *(vector.getVector() + auxDer);
			*(vector.getVector() + auxDer) = auxDato;
			auxIzq++;
			auxDer--;
		 }
 } while (auxIzq <= auxDer);
}
template <typename T>
void Operacion<T>::ordenar(Vector<T> vector, int izq, int der)
{
	 intercambiar(vector, izq, der);
	 if (izq < auxDer)
	 	ordenar(vector, izq, auxDer);
	 if (auxIzq < der)
	 	ordenar(vector, auxIzq, der);
}
template <typename T>
void Operacion<T>::ordenarL(Vector<T> vector,int izq, int der,function<void(Vector<T> &vector,int&,int&)>lambda)
{
	 intercambiar(vector, izq, der);
	 lambda(vector,izq,der);
	 if (izq < auxDer)
	 	ordenarL(vector,izq,auxDer,lambda);
	 if (auxIzq < der)
	 	ordenarL(vector,auxIzq,der,lambda);
}
template <typename T>
void Operacion<T>::intercambiarDes(Vector<T> vector, int primero, int ultimo) {
 int i,j,centro,aux,pivote;
pivote= *(vector.getVector() + ((primero + ultimo) / 2));
i = primero;
j = ultimo;
do
{
while((*(vector.getVector() + i) > pivote)) i++;
while((*(vector.getVector() + j) < pivote)) j--;
if(i<=j)
{
aux = (*(vector.getVector() + i));
(*(vector.getVector() + i)) = (*(vector.getVector() + j));
(*(vector.getVector() + j)) = aux;
i++;
j--;		
}	
} while(i<=j);
	if(primero<j)
		intercambiarDes(vector,primero,i-1);
	if(i<ultimo)
		intercambiarDes(vector,j+1,ultimo);
}




