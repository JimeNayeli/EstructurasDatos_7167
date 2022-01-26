/*	Universidad de las Fuerzas Armadas "ESPE"
*	Proyecto Final Segundo Parcial
*	Bolaños Mateo, Gonzalez Ariel, Tutillo Jimena
*	10/01/2022
*	25/01/2022
*	7167 Estructura de datos
*/

/**
* @file Lista.h
* @version 1.0
* @date 25/01/2022
* @author Bolaños Mateo, Gonzalez Ariel, Tutillo Jimena
* @title Proyecto Final Segundo Parcial
*/

#pragma once
#include "Nodo.h"
#include <ctime>
#include <random>
#include <functional>
#include <iostream>
using namespace std;

/**
* @brief Lista clase de tipo template que permite almacenar los datos de una cadena
*/
template <class T>
class Lista
{
public:
	/**
	* @brief listaVacia
	* @return bool
	*/
	bool listaVacia();
	/**
	* @brief Lista constructor vacio de la clase
	*/
	Lista<T>();
	/**
	* @brief insertar_por_la_cola
	* @param recibe un dato de tipo generico
	*/
	void insertar_por_la_cola(T);
	/**
	* @brief set_primero
	* @param recibe un dato de tipo Nodo*
	*/
	void set_primero(Nodo<T>*);
	/**
	* @brief get_primero
	* @return Nodo*
	*/
	Nodo<T>* get_primero();
	/**
	* @brief set_actual
	* @param recibe un dato de tipo Nodo*
	*/
	void set_actual(Nodo<T>*);
	/**
	* @brief get_actual
	* @return Nodo*
	*/
	Nodo<T>* get_actual();
	/**
	* @brief insertar_por_la_cabeza
	* @param recibe un dato de tipo generico
	*/
	void insertar_por_la_cabeza(T);
	/**
	* @brief borrar_por_la_cola
	*/
	void borrar_por_la_cola();
	/**
	* @brief borrar_por_la_cabeza
	*/
	void borrar_por_la_cabeza();
	/**
	* @brief mostrar
	*/
	void mostrar();
	/**
	* @brief empty_stack
	* @return bool
	*/
	bool empty_stack();
	/**
	* @brief llenar_aleatorio_lista
	*/
	void llenar_aleatorio_lista();
	/**
	* @brief vaciar_lista
	*/
	void vaciar_lista();
	/**
	* @brief maximo_comun_divisor
	* @param recibe un dato de tipo generico
	* @return T
	*/
	T maximo_comun_divisor(T);
	/**
	* @brief contar_elementos
	* @return T
	*/
	T contar_elementos();
private:
	Nodo<T>* primero;
	Nodo<T>* actual;
};

template<class T>
void Lista<T>::mostrar()
{
	Nodo<T>* temporal = this->primero;
	while (temporal) {
		cout << temporal->get_dato() << " " << endl;
		temporal = temporal->get_siguiente();

	}
	cout << endl;
}
template<class T>
void Lista<T>::vaciar_lista() {
	while (listaVacia()) {
		borrar_por_la_cola();
	}
}
template<class T>
bool Lista<T>::listaVacia()
{
	return (this->primero == NULL);
}
template<class T>
bool Lista<T>::empty_stack()
{
	return (this->primero == NULL);
}
template<class T>
Lista<T>::Lista()
{
	this->primero = NULL;
	this->actual = NULL;
}
template<class T>
void Lista<T>::insertar_por_la_cola(T val)
{
	Nodo<T>* nuevo = new Nodo<T>(val, NULL);
	if (listaVacia()) {
		this->primero = nuevo;
	}
	else {
		this->actual->set_siguiente(nuevo);
	}
	this->actual = nuevo;
}
template<class T>
void Lista<T>::set_primero(Nodo<T>* new_primero) {
	this->primero = new_primero;
}
template<class T>
Nodo<T>* Lista<T>::get_primero() {
	return primero;
}
template<class T>
void Lista<T>::set_actual(Nodo<T>* new_actual) {
	this->actual = new_actual;
}
template<class T>
Nodo<T>* Lista<T>::get_actual() {
	return actual;
}
template<class T>
void Lista<T>::insertar_por_la_cabeza(T val)
{
	Nodo<T>* nuevo = new Nodo<T>(val, NULL);

	if (listaVacia()) {
		this->actual = nuevo;
	}
	else {
		nuevo->set_siguiente(this->primero);
	}
	this->primero = nuevo;
}
template<class T>
void Lista<T>::borrar_por_la_cola()
{
	if (!listaVacia()) {
		Nodo<T>* temp = this->actual;
		Nodo<T>* temp1 = this->primero;
		while (temp1->get_siguiente()->get_siguiente() != NULL) {
			temp1 = temp1->get_siguiente();
		}
		temp1->set_siguiente(NULL);
		this->actual = temp1;
		free(temp);
	}
}
template<class T>
void Lista<T>::borrar_por_la_cabeza()
{
	if (!listaVacia()) {
		Nodo<T>* temp;
		temp = this->primero;
		this->primero = this->primero->get_siguiente();
		free(temp);
	}
}
template<class T>
void Lista<T>::llenar_aleatorio_lista()
{
	Nodo<T>* temp = this->primero;
	std::srand(std::time(nullptr));
	int aleatorio = 0;
	while (aleatorio != 5) {
		aleatorio = 1 + rand() % (6);
		if (aleatorio == 2 || aleatorio == 4) {
			insertar_por_la_cola(aleatorio);
		}
	}
}
template<class T>
T Lista<T>::maximo_comun_divisor(T elementos)
{
	int mcd = 0;
	int contador = 0;
	Nodo<T>* temporal = this->primero;
	for (int i = 1; i < 1000; i++) {
		contador = 0;
		temporal = this->primero;
		while (temporal) {

			if (temporal->get_dato() % i == 0) {

				contador = contador + 1;
			}
			temporal = temporal->get_siguiente();


		}

		if (elementos == contador) {
			mcd = i;
		}

	}

	return T(mcd);
}
template<class T>
T Lista<T>::contar_elementos()
{
	int elementos = 0;
	Nodo<T>* temporal = this->primero;
	while (temporal) {
		elementos = elementos + 1;
		temporal = temporal->get_siguiente();

	}
	return T(elementos);
}


