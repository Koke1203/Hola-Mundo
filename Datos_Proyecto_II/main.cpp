#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <stack>
#include <string>
using namespace std;


bool ValidaParentesis(string expresion) {
	stack<char> pila;
	bool esValida = true;
	char c, aux;

	for (string::size_type i = 0; i < expresion.size(); ++i) {
		c = expresion[i];
		if (c == '(' || c == '[' || c == '{')
			pila.push(c);
		else if (c == ')' || c == ']' || c == '}')
			if (pila.empty())
				esValida = false;
			else {
				aux = pila.top();
				pila.pop();
				if ((c == '(' && aux != ')') || (c == '[' && aux != ']') || (c == '{' && aux != '}'))
					esValida = false;
			}
	}
	if (!pila.empty())
		return false;
	return esValida;
}



int main() {

	ifstream fin("program.txt");

	if (!fin.is_open()) {
		cout << "Error al abrir el archivo \n";
		exit(0);
	}
	string linea, archivo;
	while (getline(fin, linea)) {
		archivo += linea + "\n";
	}
	cout << endl <<endl;

	if (ValidaParentesis(archivo))
		cout << "Parentesis correctos" << endl << endl;
	else
		cout << "Parentesis con problemas" << endl << endl;

	return 0;
}