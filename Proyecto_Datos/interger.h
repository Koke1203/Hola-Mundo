#pragma once


#include"lista.h"
#include"vector.h"
#include<string>
#include<iostream>
#include<fstream>
using namespace std;
class interger
{

private:

	lista_doble_enlazada* lis;
	int cantidad_nodos;
	long pos;
	int hola;
public:

	interger();
	interger(int a){
		hola = a;
	}
	~interger();

	interger multiplicacion_intergers(interger in1, interger in2);

	int obtener_cantidad_nodos();
	string operator[](long pos);
	long obtener_numero_digitos() {
		return obtener_cantidad_nodos() * 16;
	}

	operator int()
	{
		return hola;
	}

	void mostrarNumero();

	void mostrarNumeroRellenandoOs();
	void mostrarNumeroAComoSeAlmacena();
	void ConvertirObjeto(string s1);


	//--------------------METODO PARA GUARDAR EL INTERGER EN UN TXT-------------------

	string toString();

	void guardar_numero_txt();
	interger* cargar_numero();

};