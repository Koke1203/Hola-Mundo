#include <iostream>
#include <string>
#include "integer.h"
#include "lista.h"
using namespace std;

struct Integer {   //convertidor de numeros

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