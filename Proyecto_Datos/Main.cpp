
// main.cpp
// Autores: Gabriel Barboza Carvajal , Jorge Canales Espinoza , Joan Corea Aguilar
// Descripcion: archivo principal donde se accede a todas las clases para utilizarlas y realizar operaciones deseadas.

#include"interger.h"

int main()
{
	interger in1;
	in1.ConvertirObjeto("2");
	interger in2;
	in2.ConvertirObjeto("2");
	interger in3;
	in3.ConvertirObjeto("2");

	in1*= in2;

	cout << in1 << endl;

	in1 *= in3;

	cout << in1 << endl;


	system("pause");
	return 0;
}
