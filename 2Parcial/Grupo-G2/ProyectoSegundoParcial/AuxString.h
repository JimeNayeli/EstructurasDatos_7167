/*	Universidad de las Fuerzas Armadas "ESPE"
*	Proyecto Final Segundo Parcial
*	Bolaños Mateo, Gonzalez Ariel, Tutillo Jimena
*	10/01/2022
*	25/01/2022
*	7167 Estructura de datos
*/

/**
* @file AuxString.h
* @version 1.0
* @date 25/01/2022
* @author Bolaños Mateo, Gonzalez Ariel, Tutillo Jimena
* @title Proyecto Final Segundo Parcial
*/

#pragma once
#include <string>
using namespace std;
class AuxString
{
public:
	/**
	* @brief longitd
	* @param cadena recibe un dato de tipo cadena de caracteres
	* @return int
	*/
	int longitud(string);
	/**
	* @brief extraer
	* @param cadena recibe un dato de tipo cadena de caracteres
	* @param a recieb un dato de tipo entero
	* @param b recibe un dato de tipo entero
	* @return string
	*/
	string extraer(string, int, int);
	/**
	* @brief igual
	* @param recibe dos datos de tipo cadena de caracteres
	* @return bool
	*/
	bool igual(string, string);
	/**
	* @brief atoi
	* @param recibe un dato de tipo caracter
	* @return int
	*/
	int atoi(char);
	/**
	* @brief stoi
	* @param recibe un dato de tipo cadena de caracteres
	* @return int
	*/
	int stoi(string);
	/**
	* @brief reves
	* @param recibe un dato de tipo cadena de caracteres
	* @return string
	*/
	string reves(string);
	/**
	* @brief poner_en
	* @param recibe un dato de tipo int y una cadena de caracteres
	* @return char
	*/
	char poner_en(int, string);
	/**
	* @brief is_number
	* @param cad recibe una cadena de caracteres
	* @return bool
	*/
	bool is_number(string cad);
};