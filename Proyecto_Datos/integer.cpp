#include <iostream>
#include <string>
#include "integer.h"
#include "lista.h"
using namespace std;

struct Integer {   //convertidor de numeros

};

void ConvertirObjeto() {//realiza la conversion de ya sea un int o long en Integer
		// Take any string 
	string s1 = "4894351688451728769255875819203593712573192578591813957937159217863918276973967263971836279632878927";
	int* vector = new int[s1.size()];

	for (int i = 0; i < s1.size();i++) {
		vector[i] = stoi(s1.substr(i, 1));    //divide el string en digitos y se parsea a entero.
	}

	struct nodo_simple* inicio = nullptr;

	for (int i = 0; i < s1.size();i++) {
		InsertarLista(inicio, vector[i]);  //guarda cada digito del string en la lista como entero
	}
}