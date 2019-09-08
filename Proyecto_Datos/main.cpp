// C++ program to compute factorial of big numbers 
#include<iostream> 
#include<string.h>
#include<string>
#include "Lista.h"
using namespace std;

// Driver program 
int main() {

	// Take any string 
	string s1 = "4894351688451728769255875819203593712573192578591813957937159217863918276973967263971836279632878927";
	int* vector = new int[s1.size()];

	for (int i = 0; i < s1.size();i++) {
		vector[i] = stoi(s1.substr(i, 1));
	}

	struct nodo_simple* inicio = nullptr;

	for (int i = 0; i < s1.size();i++) {
		InsertarLista(inicio, vector[i]);
	}

	MostrarSimple(inicio);

	cout << endl;
	return 0;
}