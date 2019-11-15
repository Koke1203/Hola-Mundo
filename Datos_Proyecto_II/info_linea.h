
// info_linea.h
// Autor: Gabriel Barboza Carvajal ,Joan Corea, Jorge Canales
// Descripción: objeto que almacena informacion de cada linea con sus datos 
// y ademas el num de esa linea , para asi facilitar el envio de un error...

//------------------------------------------------------------------------

#ifndef FOO_BAR_BAZ_H_
#define FOO_BAR_BAZ_H_
#include<string>
using namespace std;

class info_linea {

public:
	string lineaDatos;
	int numLinea;
	string msjError;

	info_linea(string lin, int numLi)
	{
		this->lineaDatos = lin;
		this->numLinea = numLi;
	}

	string obtener_info(string a)
	{
		msjError += "Error-Linea " + std::to_string((numLinea+1)) + ": " + lineaDatos+" "+a + "\n";
		return msjError;
	}

	int getNumLinea()
	{
		return numLinea;
	}

	friend ostream& operator << (ostream& o, info_linea& in)
	{
		o << in.lineaDatos;
		return o;
	}

	void setLineaDatos(string a)
	{
		lineaDatos = a;
	}

	string get_linea_datos()
	{
		return lineaDatos;
	}

};

#endif  // FOO_BAR_BAZ_H_

//------------------------------------------------------------------------
