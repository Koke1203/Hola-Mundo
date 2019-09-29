

// interger.h
// Autores: Gabriel Barboza Carvajal , Jorge Canales Espinoza , Joan Corea Aguilar

//----------|---------------------------------------------------------------------------------------|
//			|	D E S C R I P C I O N __ D E __ L A__ E S T R U C T U R A___ U T I L I Z A D A	    |
//----------|---------------------------------------------------------------------------------------|

//	la clase interger esta compuesta por una lista doblemente enlazada que contiene nodos que a su vez
//	almacenan un vector de tipo short, con 4 celdas que se almacenaran 4 digitos por celda para un total de
//	16 digitos por nodo, utilizando 8 bytes para almacenar 16 digitos asi reduciendo el consumo de memoria para
//	almacenar los digitos, utilizamos el tipo short ya que va de un rango de - 32000 a 32000, asi aprovechamos bien
//	el tipo de dato short y ademas con esto podemos multiplicar una celda del vector por otra sin que el resultado sea muy grande para
//	poder almacenarlo en un int y asi poder realizar operaciones mas facil y usando bien la memoria.
//	entonces :
//	tenemos un total de 2bytes por celda
//	y el arreglo contiene 4 celdas.
//	el espacio libre de la estructura es en el caso que solo se
//	fuera a guardar un digito, se estaria utilzando 8 bytes para un digito
//	en el que caso de que hubiesen 17 digitos habria un total de 18 bytes para 17 digitos
//	pero en que caso que se utilize el resto del vector y se llenara hasta los 32 digitos se estaria utilizando
//	igualmente 16 bytes para 32 digitos.
//	el espacio libre de la estructura esta determinado
//	d(nodos, 8bytes) = ((nodos * 16) - numero_digitos) / 2;// es igual a los bytes que no se estan utilizando.

//----------|---------------------------------------------------------------------------------------|
//			|	------------------->>>> F I N __ D E S C R I P C I O N <<<<<----------------	    |
//----------|---------------------------------------------------------------------------------------|

#ifndef INTERGER_H_

#define INTERGER_H_
#include"lista.h"
#include"vector.h"
#include<string>
#include<iostream>
#include<fstream>
#include"cadena.h"
#include"utiles.h"

short const CERO = 0;

using namespace std;

class interger{

private:

	lista_doble_enlazada* lis;
	int cantidad_nodos;
	long pos;
	int cont;
public:

	interger();
	
	~interger();


	int obtener_cantidad_nodos();

	string operator[](long pos);

	long obtener_numero_digitos() {
		return obtener_cantidad_nodos() * 16;
	}

	//Sobrecarga de operadores de comparacion
	bool operator==(interger& num2);
	bool operator!=(interger& num2);
	bool operator>(interger& num2);
	bool operator<(interger& num2);
	bool operator>=(interger& num2);
	bool operator<=(interger& num2);
	//------------------------------------

	void mostrarNumero();
	void mostrar_resultado_numero_multi();
	void mostrarNumeroRellenandoOs();
	void mostrarNumeroAComoSeAlmacena();
	void ConvertirObjeto(string s1);

	//--------------------METODO PARA GUARDAR EL INTERGER EN UN TXT-------------------

	string toString();

	void guardar_numero_txt(string nombre_archivo);

	//void cargar_numero(string nombre_archivo);

	int digitos_numero();

	vector* obtener_nodo(int pos);


//------------------------------------multiplicacion de intergers-----------------------------------------------

//-------------------------- __________M O D I F I C A C I O N ___ P A R A ___ I N T E R G E R S _____-----------------------------
	int getCarry(int num);




interger* multiply(interger num1, interger  num2);


interger& operator * (interger& num2);
interger& operator *=(interger& num2);

friend ostream& operator << (ostream& o,  interger& in);

void cargar_numero_alreves(string nombre_archivo);

int num(char a);
int num(string a);

};

#endif INTERGER_H_