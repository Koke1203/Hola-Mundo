// utiles.h
// Autores: Gabriel Barboza Carvajal , Jorge Canales Espinoza , Joan Corea Aguilar
// Descripción: clase de utiles para hacer conversiones sencillas de int a string y viceversa...

#ifndef FOO_BAR_BAZ_H_
#define FOO_BAR_BAZ_H_

#include <string>
#include <sstream>
#include<iostream>

using namespace std;

class utiles
{
public:

	static int convertir_int(string);
	static double convertir_double(string);
	static string convertir_string(int);
	static int quitar_ultimo_digito(int a)
	{

		string str_a = utiles::convertir_string(a);

		str_a = str_a.substr(0, str_a.length() - 1);

		//cout << " str : " << str_a << endl;

		a = utiles::convertir_int(str_a);
		return a;
	}

};


#endif  // FOO_BAR_BAZ_H_