//symbol_table.h
//Autores: Gabriel Barboza, Jorge Canales y Joan Corea
//Descripcion: Encabezado del archivo symbol_table.cpp

#ifndef TABLE_
#define TABLE_

#include<iostream>
using namespace std;

const int MAX = 100;


//Nodo que se usa para la tabla
class Nodo {
public:
	string identificador, alcance, tipo;
	int linea;
	Nodo* next;

	Nodo()
	{
		next = NULL;
	}

	Nodo(string llave1, string alcance1, string tipo1, int linea1)
	{
		this->identificador = llave1;
		this->alcance = alcance1;
		this->tipo = tipo1;
		this->linea = linea1;
		next = NULL;
	}

	friend class SymbolTable;
};

class SymbolTable {
public:
	Nodo* head[MAX];

	SymbolTable()
	{
		for (int i = 0; i < MAX; i++)
			head[i] = NULL;
	}

	int funcion_hash(string id);  //funcion de hash, para sacar los id
	bool insertar(string,string,string,int);

	string buscar(string);

	bool borrar_identificador(string);

	bool modificar(string,string,string,int);
};

#endif