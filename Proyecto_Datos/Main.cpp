
// main.cpp
// Autores: Gabriel Barboza Carvajal , Jorge Canales Espinoza , Joan Corea Aguilar
// Descripcion: archivo principal donde se accede a todas las clases para utilizarlas y realizar operaciones deseadas.

#include"interger.h"

int main()
{

	interger in1;
	in1.ConvertirObjeto("22");
	interger in2;
	in2.ConvertirObjeto("2");

	cout << in1 * in2 << endl;


	system("pause");
	return 0;
}
