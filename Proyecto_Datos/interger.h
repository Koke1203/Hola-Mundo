// 
// Autores: Gabriel Barboza, Jorge Canales y Joan Corea
// Descripcion:
#ifndef LISTA_H
#define LISTA_H

#include"lista.h"
#include"vector.h"
#include<string>
#include<iostream>
using namespace std;
class interger
{

private:

	lista_doble_enlazada<vector>* lis;

public:

	interger()
	{
		lis = new lista_doble_enlazada<vector>();
	}

	void mostrarNumero()
	{
		nodo<vector>* aux = lis->getUltimo();

		while (aux != nullptr) {
			//cout << *aux->getPtr() << endl;

			aux->getPtr()->mostrarAlreves();
			aux = aux->getAnt();
		}
		/*
				while (aux)
				{
					aux->getPtr()->mostrarAlreves();
					aux = aux->getSig();
				}*/
	}


	void mostrarNumeroAComoSeAlmacena()
	{
		nodo<vector>* aux = lis->getPrimero();

		while (aux)
		{
			aux->getPtr()->mostrarNormal();
			aux = aux->getSig();
		}
	}

	void ConvertirObjeto(string s1)//, nodo_simple* lista) {//realiza la conversion de ya sea un int o long en Integer
		// Take any string
	{
		int* vec = new int[(unsigned int)s1.size()];
		//int aux[4];
		vector v;
		int cont = 0;
		vector* aux = new vector();
		for (int i = s1.size() - 1; i >= 0; i--) {
			vec[cont] = stoi(s1.substr(i, 1));    //divide el string en digitos y se parsea a entero.
			cout << "vec[ " << cont << "] " << vec[cont] << endl;
			cont++;
		}

		for (int i = 0; i < s1.size(); i += 4) {
			for (int j = 0; j < 4; j++) {
				aux->insertarElemento(vec[i + j]);
			}
			cout << "i : " << i << endl;
			v = new vector(*aux);
			cout << " v : " << v << endl;
			aux->borrarElementos();
			//lis->insertar_final(new vector(v));
			lis->insertar_elemento(new vector(v));
		}
		//lis->imprimelista();
		//lis->imprimir_lista_invertida();
		//lis->imprimir_lista();
	}


};

#endif