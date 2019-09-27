
#include"interger.h"

bool EsIgual(interger num1, interger num2);

int main()
{

	interger in1;
	in1.ConvertirObjeto("12345676");
	interger in2;
	in2.ConvertirObjeto("12");
	vector* result = in1.obtener_nodo(0); 

	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	cout << endl << endl << endl;
	
	//cout<<"Resultado del primer digito del primer nodo: "<<result->mostrarNormal()<<endl;

	result->mostrarNormal();

	/*if (!EsIgual(in1, in2)) {
		cout << "Numeros son diferentes!!" << endl;
	}*/
	
	/*interger *res=NULL;

	res = res->mult(in1, in2);

	cout << ".--------------------." << endl;
	cout << res->toString() << endl;*/
	
	/*
	Probando la sobrecarga con un tipo de dato diferente, en este caso int.
	int dato = 2397248;
	interger* in = new interger(dato);
	in->mostrarNumero();*/

	
	system("pause");
	return 0;
}

//para saber si dos intergers son iguales, tengo que pasarlo a la clase interger.cpp, y realizar la sobrecarga del operador
bool EsIgual(interger num1, interger num2) {
	bool es_igual = false;
	if (num1.digitos_numero() != num2.digitos_numero()) {  //automaticamente se sabe que son diferentes
		return es_igual;
	}
	else if(num1.digitos_numero() == num2.digitos_numero()){ //se sabe que tiene el mismo tamanio
		vector vector1, vector2;
		for (long i = 0; i < num1.digitos_numero();i++) {
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