// main.cpp
// Autores: Gabriel Barboza, Jorge Canales y Joan Corea
// Descripcion: archivo principal del proyecto
#include<iostream> 
#include<string>
#include "lista.h"
#include "integer.h"
using namespace std;

// Driver program 
int main() {

	struct nodo_simple* inicio = NULL;
	cout << "";
	string s1 = "12305674456";
	
	//ConvertirObjeto(s1, inicio);
	// Take any string
	int* vector = new int[s1.size()];
	int aux[4];
	for (int i = 0; i < s1.size();i++) {
		vector[i] = stoi(s1.substr(i, 1));    //divide el string en digitos y se parsea a entero.
	}
	for (int i = 0; i < s1.size();i += 4) {
		for (int j = 0; j < 4;j++) {
			aux[j] = vector[i + j];
		}
		InsertarLista(inicio, aux);  //guarda cada digito del string en la lista como entero
	}
	MostrarSimple(inicio);



	//para validar que el vector no guarde basura, tengo que irme a la clase lista y validar que el numero no sea mayor que un digito,
	//porque ya estaria guardando basura si fuera ese el caso, se debe guardar null

	cout << endl;
	return 0;
}