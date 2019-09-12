// main.cpp
// Autores: Gabriel Barboza, Jorge Canales, Joan Corea.
// Descripcion: clase principal del programa.
#include"interger.h"

int main(int argc, char* argv){
	/*
		lista<vector> lista;

		lista<vect

		nodo<vector> n;


		vector *v1=new vector();

		v1->insertarElemento(1);
		v1->insertarElemento(2);
		v1->insertarElemento(3);
		v1->insertarElemento(4);

		lista.insertar_final(v1);
		vector* v2 = new vector();

		v2->insertarElemento(5);
		v2->insertarElemento(6);
		v2->insertarElemento(7);
		v2->insertarElemento(8);

		lista.insertar_final(v2);

		lista.imprimelista();
	*/

	interger in1;

	string s = "1234";

	in1.ConvertirObjeto(s);

	cout << "_-------------------------------------------------" << endl;
	cout << "_---------MOSTRANDO NUMERO NORMAL-------------------" << endl << endl;

	in1.mostrarNumero();


	cout << "_-------------------------------------------------" << endl;
	cout << "_---------MOSTRANDO NUMERO Diferente-------------------" << endl << endl;
	in1.mostrarNumeroAComoSeAlmacena();
	cout << endl << endl;
	//vector* v1 = new vector();
	//v1->insertarElemento(1);
	//v1->insertarElemento(2);
	//v1->insertarElemento(3);
	////v1->insertarElemento(4);

	//vector* v2 = v1;


	//cout << *v2 << endl;
	//cout << "cant : " << v2->getCant();

	system("pause");
	return 0;
}