const int MAX = 100;
#include<iostream>
using namespace std;

class SymbolTable {
	Node* head[MAX];

public:
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