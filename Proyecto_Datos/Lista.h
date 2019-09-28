// lista_doble_enlazada.h
// Autor: Gabriel Barboza Carvajal
// Descripción: clase lista que contiene nodos genericos para su implementacion.

//------------------------------------------------------------------------

#ifndef LISTA_DOBLE_ENLAZADA_H_
#include"nodo.h"
#define LISTA_DOBLE_ENLAZADA_H_

class lista_doble_enlazada
{
private:
	nodo* inicio;
	nodo* actual;
	int cantidad_nodos;
public:
	int get_cantidad_nodos() {
		return cantidad_nodos;
	}
	lista_doble_enlazada();
	~lista_doble_enlazada();
	bool es_vacia();
	nodo* getPrimero();
	nodo* getUltimo();
	void insertar_elementoPrimero(vector* v);
	void insertar_elemento(vector* v);
	void borrar_inicio();
	void borrar_final();
	nodo* obtener_nodo(long indice);
	vector* buscar_elemento(vector& v);
	bool borrar_elemento(vector& elemento);
	//falta borrar elemento por indice
	bool borrar_elemento_indice(int indice);
	bool imprimir_lista();
	bool imprimir_lista_invertida();

	void detalles();
};



//------------------------------------------------------------------------


inline lista_doble_enlazada::lista_doble_enlazada()
{
	inicio = NULL;
	actual = NULL;
}


inline lista_doble_enlazada::~lista_doble_enlazada()
{
	nodo* aux = inicio;

	while (inicio != NULL)
	{

		aux = inicio;
		inicio = inicio->getSig();

		delete aux;

	}
}


inline void lista_doble_enlazada::insertar_elementoPrimero(vector* a)
{
	cout << "Elemento a insertar : " << *a << endl;
	nodo* nuevo = new nodo();
	nuevo->setVec(a);     // Guardamos el valor en el nodo
	nuevo->setSig(nullptr);   // El puntero siguiente apuntaría a NULL
	nuevo->setAnt(nullptr);   // el punterio anterior apuntaria a null

	// Si la lista está vacía, el nodo creado se convierte en el primer elemento
	if (inicio == nullptr)
	{
		nuevo->setAnt(inicio);
		nuevo->setSig(inicio);
		inicio = nuevo;
	}
	else {                      // Si ya existen elementos en la lista, entonces necesitamos
		nodo* aux = inicio;     // un auxiliar para recorrer la lista y colocarnos al final
		nuevo->setSig(aux);
		aux->setAnt(nuevo);   // Apuntamos al nodo anterios
		inicio = nuevo;
	}
	cantidad_nodos++;
}

inline void lista_doble_enlazada::insertar_elemento(vector* a)
{
	cout << "Elemento a insertar : " << *a << endl;
	nodo* nuevo = new nodo();
	nuevo->setVec(a);     // Guardamos el valor en el nodo
	nuevo->setSig(nullptr);   // El puntero siguiente apuntaría a NULL
	nuevo->setAnt(nullptr);

	// Si la lista está vacía, el nodo creado se convierte en el primer elemento
	if (inicio == nullptr)
		inicio = nuevo;
	else {                      // Si ya existen elementos en la lista, entonces necesitamos
		nodo* aux = inicio;     // un auxiliar para recorrer la lista y colocarnos al final
		while (aux->getSig() != nullptr)
			aux = aux->getSig();
		aux->setSig(nuevo);   // El último nodo apunta al nodo nuevo
		nuevo->setAnt(aux);   // Apuntamos al nodo anterios
	}
	cantidad_nodos++;
}


inline void lista_doble_enlazada::borrar_inicio()
{
	actual = inicio;
	if (inicio != nullptr)
	{
		inicio = actual->getSig();
		inicio->setAnt(NULL);
		delete actual;
	}
	cantidad_nodos--;
}



inline void lista_doble_enlazada::borrar_final()
{
	nodo* ant = nullptr;
	if (inicio != NULL and inicio->getSig() == nullptr)
	{
		delete inicio;
		inicio = nullptr;
	}
	else
	{
		actual = inicio;

		while (actual->getSig() != NULL)
		{
			ant = actual;
			actual = actual->getSig();
		}
	}
	cout << "elemento a borrar " << actual->getPtr()->toString() << endl;
	delete actual;
	ant->setSig(NULL);

}

inline nodo* lista_doble_enlazada::obtener_nodo(long indice)
{
	actual = inicio;
	long cont = 0;
	//cout << "indice  : " << indice << endl;
	/*while (actual)
	{
		if (cont == indice)
			return actual;
		actual = actual->getSig();
		cont++;
	}*/
	//cout << "cantidad nodos : " << cantidad_nodos << endl;
	while (cont < cantidad_nodos - 1 and cont != indice and actual)
	{
		//cout << "cont = " <<cont<< endl;
		actual = actual->getSig();
		++cont;
	}
	return actual;
}


inline vector* lista_doble_enlazada::buscar_elemento(vector& dato)
{
	actual = inicio;
	if (actual->getPtr() == &dato)
		return actual->getPtr();

	else

		while (actual->getPtr() != &dato and actual->getSig() != NULL)
			actual = actual->getSig();

	if (actual->getPtr() == &dato) //encontrado
		return actual->getPtr();
	else
		return NULL;
}


inline bool lista_doble_enlazada::borrar_elemento(vector& dato)
{

	actual = inicio;

	if (actual->getPtr() == &dato)
	{
		inicio = inicio->getSig();
		inicio->setAnt(nullptr);
		delete actual;
		actual = nullptr;
		cantidad_nodos--;
		return true;
	}
	else {
		nodo* anterior = NULL;
		// hay buscarlo entre la lista
		while (actual->getPtr() != &dato and actual->getSig() != NULL)
		{
			anterior = actual;
			actual = actual->getSig();
		}

		if (actual->getPtr() == &dato and actual->getSig() == NULL) {//encontrado , y si es el ultimo
			anterior->setSig(nullptr);
			delete actual; cantidad_nodos--;
			return true;
		}
		if (actual->getPtr() == &dato and actual->getSig() != NULL)// si esta por el medio
		{
			nodo* aux = actual->getSig();
			anterior->setSig(aux);
			aux->setAnt(anterior);
			delete actual;
			actual = nullptr;
			cantidad_nodos--;
			return true;
		}
		else
			return false;
	}
}



inline bool lista_doble_enlazada::borrar_elemento_indice(int indice)
{
	if (inicio == NULL or indice<0 or indice>cantidad_nodos)
		return false;
	else// se encuentra en el rango para buscarlo
	{

		int a = 0;
		imprimir_lista(); actual = inicio;
		nodo* aux = NULL;
		while (a != indice and actual->getSig() != nullptr)
		{
			aux = actual;
			actual = actual->getSig();
			a++;
		}
		if (a != 0)
			cout << *(aux->getPtr()) << endl;
		if (a == 0)//hay que eliminar el primero
		{
			borrar_inicio();
			return true;
		}
		else if (a == cantidad_nodos)//borrar el final
		{
			borrar_final();
			return true;
		}
		else//hay que borrar otros
		{
			nodo* aux2 = actual->getSig();
			aux->setSig(aux2);
			aux2->setAnt(aux);
			delete actual;
			cantidad_nodos--;
			return true;
		}

	}
}


inline bool lista_doble_enlazada::imprimir_lista()
{
	nodo* aux = inicio; int a = 0;
	cout << "NUMERO DE ELEMENTOS : " << cantidad_nodos << "." << endl;

	if (aux != nullptr)
	{

		cout << "-------Mostrando los Datos--------" << endl;
		while (aux != NULL)
		{
			cout << "N" << a++ << ". " << "dir : " << aux->getPtr() << endl <<
				*aux->getPtr() << endl;// si es un contenedor de personas , hay que sobrecargar el operador de salida

			aux = aux->getSig();
		}
		return true;
	}
	else {
		return false;
	}

	cout << "-----------------Fin de la Impresion------------------------------" << endl;
	cout << endl << endl;
}


inline bool lista_doble_enlazada::imprimir_lista_invertida()
{

	if (es_vacia()) {
		return false;
	}
	else
	{
		nodo* aux;
		aux = inicio;
		while (aux->getSig() != nullptr) {
			aux = aux->getSig();
		}
		while (aux != nullptr) {
			cout << *aux->getPtr() << endl;
			aux = aux->getAnt();
		}
		return true;
	}


}


inline void lista_doble_enlazada::detalles()
{
	nodo* aux = inicio;

	if (es_vacia() == 0)
	{

		cout << "-------Mostrando los Datos--------" << endl;
		while (aux != NULL)
		{
			cout << *(aux->getPtr()) << endl;// si es un contenedor de personas , hay que sobrecargar el operador de salida
			if (aux->getAnt() != NULL)
				cout << "El anterior de -> " << *(aux->getPtr()) << " es , " << *(aux->getAnt()->getPtr()) << endl;
			if (aux->getSig() != NULL)
				cout << "El siguiente de -> " << *(aux->getPtr()) << " es , " << *(aux->getSig()->getPtr()) << endl;
			aux = aux->getSig();
		}

	}
	else {
		cout << "la lista esta vacia " << endl;
	}

	cout << "-----------------Fin de la Impresion------------------------------" << endl;
	cout << endl << endl;
}




inline bool lista_doble_enlazada::es_vacia()
{
	return (inicio == NULL);
}


inline nodo* lista_doble_enlazada::getPrimero()
{
	if (es_vacia() == 0)
		return inicio;
	return NULL;
}

inline nodo* lista_doble_enlazada::getUltimo()
{
	nodo* aux = this->getPrimero();
	while (aux->getSig())
		aux = aux->getSig();

	return aux;
}







#endif  // FOO_BAR_BAZ_H_