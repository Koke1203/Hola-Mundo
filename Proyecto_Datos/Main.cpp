#include"interger.h"

int main()
{

	//A partir de 10 digitos ya sirve 
	interger in1;
	in1.ConvertirObjeto("1233");
	//
	interger in2;
	in2.ConvertirObjeto("1234");
	//
	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	//
	if (in1 < in2) {
		cout << "N1 es menor" << endl;
	}
	else {
		cout << "N1 es mayor" << endl;
	}


/*
	for (size_t i = 0; i < in1.obtener_numero_digitos(); i++)
	{
		cout << " i : "<<i<<"-> " <<in1[i] << endl;
	}*/

	//vector* v = in1.obtener_nodo(0);

	//cout << "vector capturado" << endl;
	//v->mostrarNormalCasillas();
	//cout << endl;

	//cout << "imprimir primer Casilla : " << v->getPrimero() << endl;
	//cout << endl << "imprimir segunda Casilla : " << v->getSegundo() << endl;
	//cout << endl << "imprimir tercera Casilla : " << v->getTercero() << endl;
	//cout << endl << "imprimir cuarta Casilla : " << v->getCuarto() << endl;

	//cout << "_---------------------usar metodo------------------" << endl;

	//cout << "posicion 0" << endl;
	//cout<<v->getNumerosPosicion(0)<<endl;
	//cout << "-------------imprimiendo interger--------------------" << endl;
	//for (size_t i = 0; i < in1.obtener_numero_digitos(); i++)
	//{
	//	cout << in1[i] << endl;
	//}

	system("pause");
	return 0;
}
