#include "utiles.h"


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
