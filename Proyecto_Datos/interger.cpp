#include "interger.h"

interger::interger() {
	lis = new lista_doble_enlazada();
	int cont = 0;
}

//Convierte un entero a interger 
interger::interger(int dato) {
	lis = new lista_doble_enlazada();
	string conversion = "";
	conversion = to_string(dato);
	ConvertirObjeto(conversion);
}

//Convierte un long a interger
interger::interger(long dato) {
	lis = new lista_doble_enlazada();
	string conversion = "";
	conversion = to_string(dato);
	ConvertirObjeto(conversion);
}

interger::~interger()
{
	lis->~lista_doble_enlazada();
	//delete lis;
}

int interger::obtener_cantidad_nodos()
{
	return lis->get_cantidad_nodos();
}

string interger::operator[](long pos)
{
	this->pos = pos;
	//cout << "pos : " << pos << endl;
	string ss;
	if ((pos / 16) > obtener_cantidad_nodos())
	{
		cout << toString() << endl;
		cout << "pos/16 : " << pos / 16 << " , cantidad : " << obtener_cantidad_nodos() << endl;
		cout << "posicion exede el tamanio del interger" << endl;
		return "-1";
	}
	else
	{
		string s;
		long pos_vector = pos;
		if (pos_vector <= 15) {
			s = lis->obtener_nodo(0)->getPtr()->retornar_numero_0s();
			//cout << " nodo # : " << 0<< endl;
			//cout << "tama : " << s.size() << endl;
			ss += s[pos_vector];
		}
		else
		{
			if (pos > this->obtener_numero_digitos())
				return "la posicion exede el tamanio del numero\n";
			else
			{
				s = lis->obtener_nodo((pos / 16))->getPtr()->retornar_numero_0s();
				//cout << " nodo # : " << (pos / 16)  << endl;
				//cout << "tama : " << s.size() << endl;

				//como acertar en la posicion + de 16
				//long pos_nodo = (pos / 16 )-1;
				//if (pos_nodo == 0)
					//pos_nodo = 1;
				//cout << "pos_nodo : " << pos_nodo << endl;
				long num_digitos_nodo_anterior = 16 * (pos / 16);
				//cout << "numero de digitos , nodo anterior : " << num_digitos_nodo_anterior << endl;
				long pos_vector = (pos - num_digitos_nodo_anterior);
				//cout <<" ( "<< pos << " - " << num_digitos_nodo_anterior << " ) -1 = " << pos_vector << endl;
				//cout << "pos vector : " << pos_vector << endl;
				if (pos_vector < 0)pos_vector = 0;
				/*cout << "---------------------------------- I M P R I M I E N D O __ N O D O -------------------------------" << endl;
				for (size_t i = 0; i < s.size(); i++)
				{
					cout << s[i];
				}cout << endl;
				cout << "---------------------------------------------------------------------------------------------------" << endl;
				cout << endl;*/
				ss += s[pos_vector];

			}
		}
		return ss;
	}
}

//interger& interger::operator*(interger in1)
//{
//}

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

void interger::mostrar_resultado_numero_multi()
{
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
	cont = num.size();
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

			if (insercion == 0)//llego al final , nuevo vector hay que a�adir
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
			cout << numero << endl;
			insercion = aux->insertarElementoFinal(numero);
			if (insercion == false)//se lleno y quedaron numeros sin almacenarse
			{
				cout << "num . size = " << num.size() << endl;
				if (num.size() == 0)
				{
					lis->insertar_elementoPrimero(new vector(*aux));//guardamos el numero anterior
					break;
				}
				else
				{
					lis->insertar_elementoPrimero(new vector(*aux));//guardamos el numero anterior
					cout << "quedo el elemento : " << numero << " , sin almacenarse " << endl;
					aux->borrarElementos();
					aux->insertarElementoFinal(numero);
					aux->mostrarNormalCasillas();
					lis->insertar_elementoPrimero(new vector(*aux));
					lis->imprimir_lista();
					return; break;
				}
				//aux->borrarElementos();//borramos los datos del aux para empezar a llenarlo denuevo
			}
			else
			{
				aux->mostrarNormalCasillas();
				cout << "<4" << endl << numero << endl;

				//lis->insertar_elemento(new vector(*aux));//creamos un vector nuevo con base al que se lleno recientemente 
				lis->insertar_elementoPrimero(new vector(*aux));
				lis->imprimir_lista();
				aux->borrarElementos();//borramos los datos del aux para empezar a llenarlo denuevo
			}

		}
	}
}

string interger::toString()
{
	nodo* aux = lis->getPrimero();
	stringstream s;
	while (aux)
	{
		s << aux->getPtr()->toString();
		aux = aux->getSig();
	}
	return s.str();
}

void interger::guardar_numero_txt(string nombre)
{
	ofstream salida(nombre);
	salida << this->toString();
	salida.close();
}

void interger::cargar_numero(string nombre)
{
	ifstream entrada(nombre);
	short cont = 1;
	vector* aux = new vector();
	bool insercion = true;
	char digi;
	string numero_4_digitos = "";


	do {
		if (!entrada.eof())
			entrada >> digi;
		else
			break;
		cout << "digi: " << digi << endl;
		numero_4_digitos += digi;
		digi = ' ';
		cout << "numero 4 digi : " << numero_4_digitos << endl;
		if (cont == 4)//llenamos un numero
		{
			cout << "numero captado : " << numero_4_digitos << endl;

			short num = atoi(numero_4_digitos.c_str());
			cout << " num short = " << num << endl;
			insercion = aux->insertarElementoPrimero(num);
			if (insercion == false)//se lleno el vector
			{

				aux->mostrarNormalCasillas();
				lis->insertar_elementoPrimero(new vector(*aux, bool()));
				aux->borrarElementos();
				aux->insertarElementoPrimero(num);
				cout << "toString : " << lis->imprimir_lista() << endl;
				system("pause");
			}
			num = 0;
			numero_4_digitos = "";// se setea el valor del string

			cont = 0;
		}

		cont++;
	} while (entrada.good() and !entrada.eof());
	if (aux->getTam() == 4 and numero_4_digitos != "")//quedaron numeros sin insertarse
	{
		cout << "ultimos digitos ojas : " << numero_4_digitos << endl;
		lis->insertar_elementoPrimero(new vector(*aux, bool()));
		aux->borrarElementos();

		aux->insertarElementoPrimero(atoi(numero_4_digitos.c_str()));
		cout << "toString _  : " << aux->toString() << endl;

		lis->insertar_elementoPrimero(new vector(*aux, bool()));

		cout << "toString : " << lis->imprimir_lista() << endl;

	}
	aux->mostrarNormalCasillas();

	cout << "--------------------------------------------------------------------" << endl;
	lis->imprimir_lista();
	cout << "--------------------------------------------------------------------" << endl;
	system("pause");
}

//metodo que obtiene la cantidad de digitos del numero
int interger::digitos_numero() {
	return cont;
}

//devuelvo el vector que contiene la posicion digitada del nodo
vector* interger::obtener_nodo(int pos) {
	return lis->obtener_nodo(pos)->getPtr();
}