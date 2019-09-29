// vector.h
// Autores: Gabriel Barboza Carvajal , Jorge Canales Espinoza , Joan Corea Aguilar
// Descripción: clase donde se almacenaran los digitos de los numeros para mejorar el espacio del interger
#ifndef VECTOR_H_
#define VECTOR_H_
#include<iostream>
using namespace std;
#include<sstream>
#define TAM 4;
#define ZERO 0;
#define UNO 1;


class vector
{

private:

	short tamanio;
	short cantidad;
	short* vec;
	short carry;
public:

	short getNumerosPosicion(int pos) {
		if (pos == 0) {
			return getPrimero();
		}
		else if (pos == 1) {
			return getSegundo();
		}
		else if (pos == 2) {
			return getTercero();
		}
		else if(pos==3){
			return getCuarto();
		}
	}

	void set_carry(short c)
	{
		carry = c;
	}

	short get_carry() {
		return carry;
	}

	vector();

	vector(const vector& vect, bool);
	vector(const vector& vect);//: tamanio(vect.tamanio), cantidad(vect.cantidad), vec(new short(vect.tamanio))

	~vector();

	friend ostream& operator<< (ostream&, vector&);


	vector& operator =(const vector& p); //  Operador de Asignación.
	vector* operator =(const vector* p); //  Operador de Asignación.


	//----------------------__ A C C E S O R E S ___----------------------------------------

	short getCuarto();
	short getTercero();
	short getSegundo();
	short getPrimero();

	short getTam();
	short getCant()
	{
		return cantidad;
	}

	//----------------------___ M U T A D O R E S ___----------------------------------------

	void setCuarto(short a);
	void setTercero(short a);
	void setSegundo(short a);
	void setPrimero(short a);
	//----------------------I N S E R C I O N ___ B O R R A D O ___----------------------------------------
	void borrarElementos();
	bool insertarElementoPrimero(short i);
	bool insertarElementoFinal(short i);
	bool insertar_conforme_se_llena(short i);
	//----------------------__I M P R E S I O N__----------------------------------------
	void mostrarRellenandoOs();
	void mostrarAlreves();
	void mostrarNormal();
	void mostrarNormalCasillas();
	string retornar_numero_0s();
	//-------------------METODO PARA OBTENER LA CANTIDAD DE DIGITOS DE UNA POSICION DEL VECTOR----------------------

	int obtener_cantidad_digitos(short num);//metodo para saber cuantos digitos tiene un numero de una posicion del vector
	string toString();
	bool llenando_vector_por_digito(short num);

};


#endif  // FOO_BAR_BAZ_H_
