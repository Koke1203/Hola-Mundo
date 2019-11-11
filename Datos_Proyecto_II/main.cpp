#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <stack>
#include <string>
#include "symbol_table.h"
#include "tools.h"
using namespace std;

int main() {
	Tools tool;
	SymbolTable tabla;
	
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

	if (tool.ValidaParentesis(archivo))
		cout << "Parentesis correctos" << endl << endl;
	else
		cout << "Parentesis con problemas de cierre o apertura" << endl << endl;

	return 0;
}