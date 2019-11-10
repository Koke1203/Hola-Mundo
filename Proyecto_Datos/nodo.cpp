#include"nodo.h"

// nodo.cpp
// Autores: Gabriel Barboza Carvajal , Jorge Canales Espinoza , Joan Corea Aguilar
// Descripción: clase nodo con la cual se va a crear el la lista del interger , contiene un vector con cuatro celdas tipo short...
//	(implementación)

nodo& nodo::operator=(nodo& a)
{

	if (this != &a)
	{
		setVec(a.getPtr());
		setSig(a.getSig());
		setAnt(a.getAnt());
	}
	return *this;
}



//-----------------------------------SobreCargaOperadores  Fin  -----------------------------------------

nodo::nodo()
{
	ant = nullptr;
	vec = new vector();
	sig = NULL;
}


nodo::nodo(vector* ptr)
{
	this->vec = ptr;
	this->sig = nullptr;
	this->ant = nullptr;

}

//------------------Mutadores-----------------------


void nodo::setVec(vector* ptr)
{
	this->vec = ptr;
}


void nodo::setSig(nodo* sig)
{
	this->sig = sig;
}


inline void nodo::setAnt(nodo* a)
{
	ant = a;
}


//------------------Accesores-------------------


vector* nodo::getPtr()
{
	return vec;
}


nodo* nodo::getSig()
{
	return sig;
}

nodo* nodo::getAnt()
{
	return ant;
}
