#pragma once

#include<iostream>
#include<fstream>
using namespace std;

class cadena
{

public:
	// Inicializa vector de tamaño N - todos los valores en cero
	cadena(int);
	// Constructor de copia
	cadena(const cadena&);
	//Destructor
	~cadena();

	void Insertar(char);
	// Elimina el cadena completamente
	void Eliminarcadena();

	void mostrarCadena();

	friend ostream& operator<< (ostream& o, const cadena& c)
	{
		for (size_t i = 0; i < c.tam; i++)
		{
			o << c.v[i] << ", ";
		}
		return o;
	}
	char& operator[](short i) {
		return v[i];
	}

	int getTam() {
		return tam;
	}

	void cargar_informacion(string nombre_archivo);

	void guardar_resultado(string nombre_archivo);

private:

	char* v;
	int capacidad;
	int tam;

	// Extiende el tamaño del cadena
	void Extender();


};