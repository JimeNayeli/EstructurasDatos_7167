#pragma once
#include "AuxString.h"
#include "Lista.h"
class Operacion
{
public:
	/**
	* @brief infix_a_prefix
	* @param cadena recibe un dato de tipo cadena de caracteres
	* @return string
	*/
	string infix_a_prefix(string);
	/**
	* @brief infix_a_postfix
	* @param cadena recibe un dato de tipo cadena de caracteres
	* @return string
	*/
	string infix_a_postfix(string);
	/**
	* @brief infix_a_funtional
	* @param cadena recibe un dato de tipo cadena de caracteres
	* @return string
	*/
	string infix_a_funtional(string);
	/**
	* @brief prefix_a_infix
	* @param cadena recibe un dato de tipo cadena de caracteres
	* @return string
	*/
	string prefix_a_infix(string);
	/**
	* @brief prefix_a_postfix
	* @param cadena recibe un dato de tipo cadena de caracteres
	* @return string
	*/
	string prefix_a_postfix(string);
	/**
	* @brief prefix_a_funtional
	* @param cadena recibe un dato de tipo cadena de caracteres
	* @return string
	*/
	string prefix_a_funtional(string);
	/**
	* @brief postfix_a_infix
	* @param cadena recibe un dato de tipo cadena de caracteres
	* @return string
	*/
	string postfix_a_infix(string);
	/**
	* @brief postfix_a_prefix
	* @param cadena recibe un dato de tipo cadena de caracteres
	* @return string
	*/
	string postfix_a_prefix(string);
	/**
	* @brief postfix_a_funtional
	* @param cadena recibe un dato de tipo cadena de caracteres
	* @return string
	*/
	string postfix_a_funtional(string);
	/**
	* @brief is_operator
	* @param char recibe un dato de tipo caracter
	* @return bool
	*/
	bool is_operator(char);
	/**
	* @brief is_trig_fun
	* @param char recibe un dato de tipo caracter
	* @return bool
	*/
	bool is_trig_fun(char);
	/**
	* @brief is_operand
	* @param char recibe un dato de tipo caracter
	* @return bool
	*/
	bool is_operand(char);
	/**
	* @brief precedence
	* @param char recibe un dato de tipo caracter
	* @return int
	*/
	int precedence(char);
	/**
	* @brief is_postfix
	* @param string recibe un dato de tipo cadena de caracteres
	* @return bool
	*/
	bool is_postfix(string);
	/**
	* @brief is_prefix
	* @param string recibe un dato de tipo cadena de caracteres
	* @return bool
	*/
	bool is_prefix(string);
	/**
	* @brief is_infix
	* @param string recibe un dato de tipo cadena de caracteres
	* @return bool
	*/
	bool is_infix(string);
	/**
	* @brief has_parenthesis
	* @param string recibe un dato de tipo cadena de caracteres
	* @return bool
	*/
	bool has_parenthesis(string);

};