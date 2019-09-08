// C++ program to compute factorial of big numbers 
#include<iostream> 
#include<string.h>
#include<string>
#include "lista.h"
#include "integer.h"
using namespace std;

// Driver program 
int main() {

	nodo_simple* lista = nullptr;

	ConvertirObjeto("4894351688451728769255875819203593712573192578591813957937159217863918276973967263971836279632878927", lista);

	MostrarSimple(lista);

	cout << endl;
	return 0;
}