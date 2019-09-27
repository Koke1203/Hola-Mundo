#include"interger.h"

bool EsIgual(interger num1, interger num2);

int main()
{

	interger in1;
	in1.ConvertirObjeto("164563131154544564654656");
	//
	interger in2;
	in2.ConvertirObjeto("164563131154544564654656");
	//
	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	//
	if (!EsIgual(in1, in2)) {
		cout << "FALSE, Es diferente " << endl;
	}
	else {
		cout << "TRUE, Son iguales!!!" << endl;
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

//para saber si dos intergers son iguales, tengo que pasarlo a la clase interger.cpp, y realizar la sobrecarga del operador
bool EsIgual(interger num1, interger num2) {
	bool es_igual = false;
	if (num1.digitos_numero() != num2.digitos_numero()) {  //automaticamente se sabe que son diferentes
		return es_igual;
	}
	else if (num1.digitos_numero() == num2.digitos_numero()) { //se sabe que tiene el mismo tamanio
		vector vector1, vector2;
		for (short i = 0; i < num1.obtener_cantidad_nodos();i++) {
			//obtengo cada contenido de cada nodo de la lista, por medio de la clase vector, luego voy comparando eso.
			vector1 = num1.obtener_nodo(0);
			vector2 = num2.obtener_nodo(0);
			for (short i = 0; i < 4;i++) {
				if (vector1.getNumerosPosicion(i) == vector2.getNumerosPosicion(i)) {
					es_igual = true;
				}
				else {
					es_igual = false;
					return es_igual;
				}
			}
		}
	}
}