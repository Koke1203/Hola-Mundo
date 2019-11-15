//tools.cpp
//Autores: Gabriel Barboza, Jorge Canales y Joan Corea
//Descripcion: Clase que se utiliza para verificaciones de tokens en el txt

#include "tools.h"

int Tools::isKeyword(string key) {
	string keywords[] = { "int", "float","string","void","if","while","return" };
	for (int i = 0; i < sizeof(keywords) / sizeof(*keywords); ++i) {
		if (key == keywords[i]) {
			return 1;
		}
	}
	return 0;
}

int Tools::isVariable(string key) {
	string variables[] = {"void","float","int","string"};
	for (int i = 0; i < 4; ++i) {
		if (key == variables[i]) {
			return 1;
		}
	}
	return 0;
}

int Tools::isOperator(char oper) {
	char operators[] = { '+','-','*','/','%','=' };
	for (int i = 0; i < 6;i++) {
		if (oper == operators[i]) {
			return 1;
		}
	}
	return 0;
}

bool Tools::ValidaParentesis(string expresion) {
	stack<char> pila;
	bool esValida = true;
	char c, aux;

	for (string::size_type i = 0; i < expresion.size(); ++i) {
		c = expresion[i];
		if (c == '(' || c == '[' || c == '{') {
			pila.push(c);
		}
		else if (c == ')' || c == ']' || c == '}'){
			if (pila.empty())
			{
				esValida = false;
			}
			else {
				aux = pila.top();
				pila.pop();
				if ((c == '(' && aux != ')') || (c == '[' && aux != ']') || (c == '{' && aux != '}'))
					esValida = false;
			}
		}
	}
	if (!pila.empty())
		return false;
	return esValida;
}