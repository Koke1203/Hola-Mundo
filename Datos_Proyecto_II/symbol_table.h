#ifndef TABLE_
#define TABLE_

#include<iostream>
using namespace std;

const int MAX = 100;


//Nodo que se usa para la tabla
class Node {
public:
	string identifier, scope, type;
	int lineNo;
	Node* next;

	Node()
	{
		next = NULL;
	}

	Node(string key, string value, string type, int lineNo)
	{
		this->identifier = key;
		this->scope = value;
		this->type = type;
		this->lineNo = lineNo;
		next = NULL;
	}

	/*void print()
	{
		cout << "Identifier's Name:" << identifier
			<< "\nType:" << type
			<< "\nScope: " << scope
			<< "\nLine Number: " << lineNo << endl;
	}*/

	friend class SymbolTable;
};


class SymbolTable {
public:
	Node* head[MAX];

	SymbolTable()
	{
		for (int i = 0; i < MAX; i++)
			head[i] = NULL;
	}

	int hashf(string id); // hash function 
	bool insertar(string id, string scope,
		string Type, int lineno);

	string buscar(string id);

	bool borrar_identificador(string id);

	bool modificar(string id, string scope,
		string Type, int lineno);
};

#endif