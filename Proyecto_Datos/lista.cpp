// lista.cpp
// Autores: Gabriel Barboza, Jorge Canales y Joan Corea
// Descripcion: Libreria que implementa operaciones de una lista

#include<iostream>
#include "lista.h"
using namespace std;

struct nodo_simple {
	int dato[4];
	//int dato;
	struct nodo_simple* next;
};

//El metodo se tiene que cambiar, ya que ahora se va guardar en un vector todos los datos

//Metodo que inserta un elemento a una pila (ya sea vector o entero)
void InsertarLista(nodo_simple*& actual, int* vector) {
	struct nodo_simple* nuevo = new nodo_simple();
	
	for(int i=0; i<4;i++){
		nuevo->dato[i] = vector[i];
	}
	
	//nuevo->dato = vector;
	nuevo->next = nullptr;
	struct nodo_simple* aux = actual;
	if (actual == nullptr) {
		actual = nuevo;
	}
	else {
		while (aux->next != nullptr) {
			aux = aux->next;
		}
		aux->next = nuevo;
	}
}

//Muestra los elementos que contiene la lista
void MostrarSimple(nodo_simple* lista) {
	while (lista) {  //mientras aux!=null
		cout << "Dato nodo: " << endl;
		for(int i=0; i<4;i++){
			cout << lista->dato[i] << endl;
		}
		cout << endl;
		//cout << lista->dato << endl;
		lista = lista->next;
	}
	cout << endl;
}