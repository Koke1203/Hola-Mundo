#include "tools.h"

bool tools::ValidaParentesis(string expresion) {
	std::stack<char> pila;
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

int tools::isKeyword(char buffer[]) {
	char keywords[32][10] = { "void","int","float","string",
							"if","while","return"};
	int i, flag = 0;

	for (i = 0; i < 32; ++i) {
		if (strcmp(keywords[i], buffer) == 0) {
			flag = 1;
			break;
		}
	}
	return flag;
}