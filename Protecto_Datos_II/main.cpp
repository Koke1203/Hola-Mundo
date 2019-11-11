#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <stack>
#include <string>
using namespace std;
#include "tools.h"



int main() {

	tools tool;
	char ch, buffer[15], operators[] = "+-*/%=";
	ifstream fin("program.txt");
	int i, j = 0;

	if (!fin.is_open()) {
		cout << "Error al abrir el archivo \n";
		exit(0);
	}

	while (!fin.eof()) {
		ch = fin.get();

		for (i = 0; i < 6; ++i) {
			if (ch == operators[i])
				cout << ch << " is operator\n";
		}

		if (isalnum(ch)) {
			buffer[j++] = ch;
		}

		else if ((ch == ' ' || ch == '\n') && (j != 0)) {
			buffer[j] = '\0';
			j = 0;

			if (tool.isKeyword(buffer) == 1)
				cout << buffer << " is keyword\n";
			else
				cout << buffer << " is indentifier\n";
		}
	}

	string linea, archivo;
	while (getline(fin, linea)) {
		archivo += linea + "\n";
	}
	cout << std::endl << std::endl;

	if (ValidaParentesis(archivo))
		cout << "Parentesis correctos" << endl << endl;
	else
		cout << "Parentesis con problemas" << endl << endl;

	return 0;
}