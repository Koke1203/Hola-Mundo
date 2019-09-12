// vector.h
// Autores: Gabriel Barboza, Jorge Canales, Joan Corea.
// Descripción: clase vector que contiene todas las propiedades y operaciones que se realizan con los vectores. 

#ifndef VECTOR_H
#define VECTOR_H_
#define TAM 4;
#define ZERO 0;
#define UNO 1;

#include<iostream>
using namespace std;

class vector
{

private:

	short tamanio;
	short cantidad;
	short* vec;

public:


	vector();

	vector(const vector& vect) //: tamanio(vect.tamanio), cantidad(vect.cantidad), vec(new short(vect.tamanio))
	{
		tamanio = vect.tamanio;
		cantidad = vect.cantidad;
		vec = new short(vect.tamanio);
		for (short i = 0; i < vect.cantidad; i++)
		{
			if (/*vect.vec[i] > 9 or */vect.vec[i] < 0)
				vec[i] = 0;
			else
				vec[i] = vect.vec[i];
		}

	}
	~vector();

	friend ostream& operator<< (ostream&, const vector&);

	vector& operator =(const vector& p); //  Operador de Asignación.
	vector* operator =(const vector* p); //  Operador de Asignación.

	short getTam();
	short getCant()
	{
		return cantidad;
	}
	void borrarElementos();
	bool insertarElemento(short i);

	void mostrarAlreves()
	{
		for (short i = 3; i >= 0; i--)
		{
			cout << vec[i] << "";
		}
		//cout << endl << endl;
	}

	void mostrarNormal()
	{
		for (short i = 0; i < 4; i++)
		{
			cout << vec[i] << "";
		}
		//cout << endl << endl;
	}

};


#endif  // FOO_BAR_BAZ_H_
