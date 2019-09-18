#include "interger.h"

interger::interger() {
	lis = new lista_doble_enlazada();
}

interger::~interger()
{
	lis->~lista_doble_enlazada();
	delete lis;
}

interger* interger::sumaIntergers(interger num1, interger num2)
{
	interger* resultado = new interger();
	int cont = 0;
	if (num1.obtener_cantidad_nodos() > num2.obtener_cantidad_nodos())//el numero 1 es mayor al segundo
		while (cont <= num1.obtener_cantidad_nodos())
		{

			cont++;
		}

	return nullptr;
}

int interger::obtener_cantidad_nodos()
{
	return lis->get_cantidad_nodos();
}

void interger::mostrarNumero()
{
	nodo* aux = lis->getUltimo();

	while (aux != nullptr) {
		//cout << *aux->getPtr() << endl;

		aux->getPtr()->mostrarAlreves();
		aux = aux->getAnt();
	}
	/*
			while (aux)
			{
				aux->getPtr()->mostrarAlreves();
				aux = aux->getSig();
			}*/
}

void interger::mostrarNumeroRellenandoOs()
{
	nodo* aux = lis->getPrimero();

	while (aux)
	{
		aux->getPtr()->mostrarRellenandoOs();
		aux = aux->getSig();
	}
}

void interger::mostrarNumeroAComoSeAlmacena()
{
	nodo* aux = lis->getPrimero();

	while (aux)
	{
		aux->getPtr()->mostrarNormalCasillas();
		aux = aux->getSig();
	}
}
/*
			_-----------------------------------------------el de arriba es la primera version
		 Metodologia de creacion de la lista :
		 vamos a obtener el numero tal como se pasa por el parametro
		 y iremos guardando 4 digitos en una posicion del arreglo asi :
		 si el numero es 12345
		 guardaremos primero los ultimos cuatro digitos en la ultma posicion de ese arreglo , es decir de derecha a izquierda
		--------------------------------------------------> [0000][0000][0001][2345]
		--------------------------------------------------> [null][null][null][2345] -> asi seria mejor creo por que no se usaria la memoria de los primeros 3.
		clase de vector modificada para que almacene los datos de manera dinamica...
		*/
void interger::ConvertirObjeto(string num)//crea la lista enlazada de vectores
{
	vector v;
	vector* aux = new vector();//_Creamos un vector de 4 posiciones que contiene elementos dinamicos...
	bool insercion;
	short numero;
	cout << "Size : " << num.size() << endl;
	for (short i = num.size(); i >= 0; i -= 4)// recorremos la entrada en numeros de cuatro en cuatro
	{


		cout << "Size : " << num.size() << endl;
		//system("pause");
		if (num.size() >= 4)
		{
			numero = short(stoi(num.substr(num.size() - 4, num.size())));
			insercion = aux->insertarElementoFinal(numero);
			cout << "> 4" << endl << numero << endl;

			if (insercion == 0)//llego al final , nuevo vector hay que añadir
			{
				//lis->insertar_elemento(new vector(*aux));//creamos un vector nuevo con base al que se lleno recientemente 
				lis->insertar_elementoPrimero(new vector(*aux));
				lis->imprimir_lista();
				aux->borrarElementos();//borramos los datos del aux para empezar a llenarlo denuevo
				cout << "----------------B O R R A N D O __ V E C T O R ---------------" << endl;
				aux->mostrarNormalCasillas();
				aux->insertarElementoFinal(numero);
				aux->mostrarNormalCasillas();
			}
			num.resize(num.size() - 4);
			cout << "Numero : " << numero << endl;
			//system("pause");

		}
		else//final del nunmero
		{
			cout << "--------------FINAL DEL NUMERO---------------" << endl;
			numero = 0;
			cout << "Size : " << num.size() << endl;
			if (num.size() != 0)
				numero = short(stoi(num.substr(0, num.size())));

			insercion = aux->insertarElementoFinal(numero);

			aux->mostrarNormalCasillas();
			cout << "<4" << endl << numero << endl;

			//lis->insertar_elemento(new vector(*aux));//creamos un vector nuevo con base al que se lleno recientemente 
			lis->insertar_elementoPrimero(new vector(*aux));
			lis->imprimir_lista();
			aux->borrarElementos();//borramos los datos del aux para empezar a llenarlo denuevo


		}
	}

}