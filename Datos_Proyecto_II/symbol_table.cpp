//symbol_table.cpp
//Autores: Gabriel Barboza, Jorge Canales y Joan Corea
//Descripcion: implementacion de tabla de simbolos 

#include "symbol_table.h"

// Modifica por medio de un identificador, retorna falso si no encuentra el identificador dentro de la tabla
bool SymbolTable::modificar(string identificador, string alcance,
	string tipo, int linea)
{
	int index = funcion_hash(identificador);
	Nodo* start = head[index];

	if (start == NULL)
		return "-1";

	while (start != NULL) {
		if (start->identificador == identificador) {
			start->alcance = tipo;
			start->linea = linea;
			return true;
		}
		start = start->next;
	}

	return false;
}


bool SymbolTable::borrar_identificador(string identicador)
{
	int index = funcion_hash(identicador);
	Nodo* tmp = head[index];
	Nodo* par = head[index];

	if (tmp == NULL) {
		return false;
	}

	if (tmp->identificador == identicador && tmp->next == NULL) {
		tmp->next = NULL;
		delete tmp;
		return true;
	}

	while (tmp->identificador != identicador && tmp->next != NULL) {
		par = tmp;
		tmp = tmp->next;
	}
	
	if (tmp->identificador == identicador && tmp->next != NULL) {
		par->next = tmp->next;
		tmp->next = NULL;
		delete tmp;
		return true;
	}else {
		par->next = NULL;
		tmp->next = NULL;
		delete tmp;
		return true;
	}
	return false;
}

//retorna 0 si no lo encuentra, retorna 1 si lo encuentra
string SymbolTable::buscar(string identicador)
{
	int index = funcion_hash(identicador);
	Nodo* start = head[index];

	if (start == NULL)
		return "0";

	while (start != NULL) {

		if (start->identificador == identicador) {
			return start->tipo;
		}

		start = start->next;
	}

	return "0"; 
}

bool SymbolTable::insertar(string identicador, string alcance,
	string tipo, int linea)
{
	int index = funcion_hash(identicador);
	Nodo* p = new Nodo(identicador, alcance, tipo, linea);
	if (head[index] == NULL) {
		head[index] = p;
		return true;
	}else {
		Nodo* start = head[index];
		while (start->next != NULL)
			start = start->next;
		start->next = p;
		return true;
	}
	return false;
}

int SymbolTable::funcion_hash(string identificador)
{
	int asciiSum = 0;
	for (int i = 0; i < identificador.length(); i++) {
		asciiSum = asciiSum + identificador[i];
	}
	return (asciiSum % 100);
}