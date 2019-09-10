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
	
	ConvertirObjeto(s1, inicio);

	cout << endl;
	return 0;
}