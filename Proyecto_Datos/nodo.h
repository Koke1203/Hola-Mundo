// nodo.h
// Autores: Gabriel Barboza, Jorge Canales, Joan Corea.
// Descripción: clase nodo que se utiliza para ligar los demas y asi generar la lista enlazada generica. 

#ifndef NODO_H_
#define NODO_H_

#include<iostream>
using namespace std;

template<class T>
class nodo {   // nodo genérico que genera nodos concretos
private:

	T* ptr;         // Flecha que a Futuro será objeto dinámico.(cualquier tipo)-		dato
	nodo<T>* sig;    // Flecha que verá a futuro otro nodo.(cualquier tipo de dato)-	signodo
	nodo<T>* ant;    // Flecha que verá a futuro otro nodo.(cualquier tipo de dato)-	signodo



public:

	nodo<T>();
	nodo<T>(T*);

	nodo<T>& operator = (const nodo<T>& a);

	//Mutadores
	void setPtr(T*);
	void setSig(nodo<T>*);
	void setAnt(nodo<T>*);
	//Accesesores
	T* getPtr();
	nodo<T>* getSig();
	nodo<T>* getAnt();
};

//------------Desarrollo de los Métodos---------------------
//------------Constructores----------------------------------


//-----------------------------------SobreCargaOperadores-----------------------------------------

template<class T>
nodo<T>& nodo<T>::operator =(const nodo<T>& a)
{
	if (this != &a)
	{
		this.setPtr(a.getPtr());
		this.setSig(a.getSig());
		this.setAnt(a.getAnt());
	}
	return this;
}



//-----------------------------------SobreCargaOperadores  Fin  -----------------------------------------
template<class T>
nodo<T>::nodo()
{
	ant = nullptr;
	ptr = NULL;
	sig = NULL;
}

template<class T>
nodo<T>::nodo(T* ptr)
{
	this->ptr = ptr;
	this->sig = nullptr;
	this->ant = nullptr;

}

//------------------Mutadores-----------------------

template<class T>
void nodo<T>::setPtr(T* ptr)
{
	this->ptr = ptr;
}

template<class T>
void nodo<T>::setSig(nodo<T>* sig)
{
	this->sig = sig;
}

template<class T>
inline void nodo<T>::setAnt(nodo<T>* a)
{
	ant = a;
}


//------------------Accesores-------------------

template<class T>
T* nodo<T>::getPtr()
{
	return ptr;
}

template<class T>
nodo<T>* nodo<T>::getSig()
{
	return sig;
}

template<class T>
inline nodo<T>* nodo<T>::getAnt()
{
	return ant;
}

#endif  // FOO_BAR_BAZ_H_
//---------------------------------Fin---------------------------------------------- 