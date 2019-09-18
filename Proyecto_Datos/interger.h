#pragma once


#include"lista.h"
#include"vector.h"
#include<string>
#include<iostream>
using namespace std;
class interger
{

private:

	lista_doble_enlazada* lis;
	int cantidad_nodos;

public:

	interger();
	~interger();

	interger* sumaIntergers(interger num1, interger num2);

	int obtener_cantidad_nodos();

	void mostrarNumero();
	void mostrarNumeroRellenandoOs();
	void mostrarNumeroAComoSeAlmacena();
	void ConvertirObjeto(string s1);


};