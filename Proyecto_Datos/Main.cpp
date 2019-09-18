
#include"interger.h"

int main()
{

	interger in1;

	string s = "12345";

	in1.ConvertirObjeto(s);

	cout << endl << "_-------------------------------------------------" << endl;
	cout << "_---------MOSTRANDO NUMERO EN LA MANERA EN LA QUE SE ALMACENA-------------------" << endl << endl;
	in1.mostrarNumeroRellenandoOs();
	cout << endl << endl;
	cout << endl << "_-------------------------------------------------" << endl;
	cout << "_---------MOSTRANDO NUMERO EN LA MANERA EN LA QUE SE ALMACENA sin Os-------------------" << endl << endl;
	in1.mostrarNumeroAComoSeAlmacena();
	cout << endl << endl;

	/*
		vector v;

		v.insertarElementoFinal(9999);
		v.insertarElementoFinal(9999);
		v.insertarElementoFinal(9999);
		v.insertarElementoFinal(0004);

		v.mostrarRellenandoOs();

		cout <<endl<<
				"		O B T E N E R : 1 _ " << v.getPrimero() << endl;
		cout << "		O B T E N E R : 2 _ " << v.getSegundo() << endl;
		cout << "		O B T E N E R : 3 _ " << v.getTercero() << endl;
		cout << "		O B T E N E R : 4 _ " << v.getCuarto() << endl;
		*/

	system("pause");
	return 0;
}