/*	Universidad de las Fuerzas Armadas "ESPE"
*	Proyecto Final Segundo Parcial
*	Bolaños Mateo, Gonzalez Ariel, Tutillo Jimena
*	10/01/2022
*	25/01/2022
*	7167 Estructura de datos
*/

/**
* @file Nodo.h
* @version 1.0
* @date 25/01/2022
* @author Bolaños Mateo, Gonzalez Ariel, Tutillo Jimena
* @title Proyecto Final Segundo Parcial
*/

#pragma once
#include <iostream>
#include <ctime>
#include <random>

/**
* @brief Nodo clase de tipo template que permite almacenar datos en espacio de memoria
*/
template <class T>
class Nodo
{
public:
	/**
	* @brief Nodo constructor de la clase con dos parametros
	* @param T recibe un dato de tipo generico
	* @param Nodo* recibe un dato de ttopo Nodo*
	*/
	Nodo<T>(T, Nodo*);
	/**
	* @brief get_dato
	* @return T
	*/
	T get_dato();
	/**
	* @brief get_dato
	* @param T recibe un dato de tipo genérico
	*/
	void set_dato(T);
	/**
	* @brief get_siguiente
	* @return Nodo*
	*/
	Nodo<T>* get_siguiente();
	/**
	* @brief get_siguiente
	* @param Nodo* recibe un dato de tipo Nodo*
	*/
	void set_siguiente(Nodo*);
private:
	T dato;
	Nodo<T>* siguiente;
};
template<class T>
Nodo<T>::Nodo(T val, Nodo* sig)
{
	sig = NULL;
	this->dato = val;
	this->siguiente = sig;
}
template<class T>
T Nodo<T>::get_dato()
{
	return this->dato;
}

template<class T>
void Nodo<T>::set_dato(T val)
{
	this->dato = val;
}

template<class T>
Nodo<T>* Nodo<T>::get_siguiente()
{
	return this->siguiente;
}
template<class T>
void Nodo<T>::set_siguiente(Nodo<T>* nuevo)
{
	this->siguiente = nuevo;
}

