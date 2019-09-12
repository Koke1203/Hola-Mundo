// vector.cpp
// Autores: Gabriel Barboza, Jorge Canales, Joan Corea.
// Descripcion: clase vector que contiene sobrecargas del vector. 

#include "vector.h"

vector::vector()
{
	tamanio = TAM;
	cantidad = 0;

	vec = new short[tamanio];

	for (short i = 0; i < tamanio; i++)
	{
		vec[i] = 0;
	}

}

vector::~vector()
{
}

vector& vector::operator=(const vector& a2)
{
	//Sobrecarga del operador de asignacion.
	cout << "Coleccion & Coleccion::operator=(const Coleccion & )" << endl;
	if (this != &a2) {
		cout << "Realizar la asignacion" << endl;
		delete[] vec; //Borrar el vector que esta en la coleccion izquierda.
		cantidad = a2.cantidad;
		tamanio = a2.tamanio;
		vec = new short[a2.tamanio];
		for (short i = 0; i < a2.tamanio; i++)
		{
			vec[i] = 0;
		}
		//Terminar de pasar los elementos entre los vectores.
		for (int i = 0; i < a2.cantidad; i++)
			vec[i] = a2.vec[i];
	}
	return *this; //Retornar una referencia es un *this.
}

vector* vector::operator=(const vector* a2)
{

	//cout << "Coleccion & Coleccion::operator=(const Coleccion & )" << endl;
	if (this != a2) {
		//cout << "Realizar la asignacion" << endl;
		delete[] vec; //Borrar el vector que esta en la coleccion izquierda.
		cantidad = a2->cantidad;
		tamanio = a2->tamanio;
		vec = new short[a2->tamanio];
		for (short i = 0; i < a2->tamanio; i++)
		{
			vec[i] = 0;
		}
		//Terminar de pasar los elementos entre los vectores.
		for (int i = 0; i < a2->cantidad; i++)
			vec[i] = a2->vec[i];
	}
	return this; //Retornar una referencia es un *this.
}

short vector::getTam()
{
	return tamanio;
}

void vector::borrarElementos()
{
	cantidad = 0;

	//vec = new short[tamanio];

	for (short i = 0; i < tamanio; i++)
	{
		vec[i] = 0;
	}

}

bool vector::insertarElemento(short i)
{
	bool a = false;
	// 0 , 1 , 2 , 3

	// 3 , 2 , 1 , 0

	if (cantidad < tamanio)
	{
		//cantidad++;
		vec[cantidad++] = i;

		a = true;
	}

	return a;
}

ostream& operator<<(ostream& sal, const vector& v)
{
	for (int i = 0; i < v.tamanio; i++)
	{
		sal << " ," << v.vec[i] << " , ";
	}
	sal << endl;
	return sal;
}