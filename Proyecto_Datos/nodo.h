


// nodo.h
// Autor: Gabriel Barboza Carvajal
// Descripción: clase nodo que se utiliza para ligar los demas y asi generar la lista enlazada generica. 

//#pragma once

#ifndef NODO_H_
#define NODO_H_
#include"vector.h"
#include<iostream>
using namespace std;

class nodo {   // nodo genérico que genera nodos concretos
private:

	vector* vec;         // Flecha que a Futuro será objeto dinámico.(cualquier tipo)-		dato
	nodo* sig;    // Flecha que verá a futuro otro nodo.(cualquier tipo de dato)-	signodo
	nodo* ant;    // Flecha que verá a futuro otro nodo.(cualquier tipo de dato)-	signodo

	short carry = 0;


public:

	void set_carry(short c)
	{
		carry = c;
	}

	short get_carry() {
		return carry;
	}

	nodo();
	nodo(vector* v);

	nodo& operator = (nodo& a);

	//Mutadores

	void setVec(vector* v);
	void setSig(nodo*);
	void setAnt(nodo*);

	//Accesesores

	vector* getPtr();
	nodo* getSig();
	nodo* getAnt();

};

#endif