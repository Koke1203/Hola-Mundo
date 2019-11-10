#include "utiles.h"

// utiles.cpp
// Autores: Gabriel Barboza Carvajal , Jorge Canales Espinoza , Joan Corea Aguilar
// Descripción: clase de utiles para hacer conversiones sencillas de int a string y viceversa...(implementación)

int utiles::convertir_int(string s) {
	stringstream r(s);
	int v = -1;
	r >> v;
	return v;
}
double utiles::convertir_double(string s) {
	stringstream r(s);
	double v = -1;
	r >> v;
	return v;
}

string utiles::convertir_string(int a)
{
	stringstream s;
	s << a;
	return s.str();
}
