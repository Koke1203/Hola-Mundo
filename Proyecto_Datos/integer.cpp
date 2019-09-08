// integer.cpp 
// Autores: Gabriel Barboza, Jorge Canales y Joan Corea
// Descripcion: Objeto integer que va contener numeros grandes
#include <iostream>
#include <string>
#include "integer.h"
#include "lista.h"
using namespace std;

struct Integer {  
	//se declara la lista
	struct nodo_simple* inicio = NULL;
	
	Integer() {}

	Integer(int num) {
		//se convierte el numero
		ConvertirObjeto(to_string(num),inicio);
	}

	Integer(long num) {
		//se convierte el numero
		ConvertirObjeto(to_string(num),inicio);
	}
};

void ConvertirObjeto(string s1, nodo_simple* lista) {//realiza la conversion de ya sea un int o long en Integer
	// Take any string
	int* vector = new int[s1.size()];

	for (int i = 0; i < s1.size();i++) {
		vector[i] = stoi(s1.substr(i, 1));    //divide el string en digitos y se parsea a entero.
	}

	for (int i = 0; i < s1.size();i++) {
		InsertarLista(lista, vector[i]);  //guarda cada digito del string en la lista como entero
	}

	MostrarSimple(lista);
}