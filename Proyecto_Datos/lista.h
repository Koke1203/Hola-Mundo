// lista.h
// Autores: Gabriel Barboza, Jorge Canales, Joan Corea.
// Descripción: clase lista que contiene nodos genericos para su implementacion.ss

#ifndef LISTA_DOBLE_ENLAZADA_H_
#define LISTA_DOBLE_ENLAZADA_H_

#include"nodo.h"

template <class T>
class lista_doble_enlazada
{
private:
	nodo<T>* inicio;
	nodo<T>* actual;

public:
	int cantnodos;
	lista_doble_enlazada();
	~lista_doble_enlazada();
	bool es_vacia();
	nodo<T>* getPrimero();
	nodo<T>* getUltimo();
	void insertar_elemento(T*);
	void borrar_inicio();
	void borrar_final();
	T* buscar_elemento(T&);
	bool borrar_elemento(T& elemento);
	//falta borrar elemento por indice
	bool borrar_elemento_indice(int indice);
	bool imprimir_lista();
	bool imprimir_lista_invertida();

	void detalles();
};



//------------------------------------------------------------------------

template<class T>
inline lista_doble_enlazada<T>::lista_doble_enlazada()
{
	inicio = NULL;
	actual = NULL;
}

template<class T>
inline lista_doble_enlazada<T>::~lista_doble_enlazada()
{
	nodo<T>* aux = inicio;

	while (inicio != NULL)
	{

		aux = inicio;
		inicio = inicio->getSig();

		delete aux;

	}
}

template<class T>
inline void lista_doble_enlazada<T>::insertar_elemento(T* a)
{
	nodo<T>* nuevo = new nodo<T>();
	nuevo->setPtr(a);     // Guardamos el valor en el nodo
	nuevo->setSig(nullptr);   // El puntero siguiente apuntaría a NULL
	nuevo->setAnt(nullptr);

	// Si la lista está vacía, el nodo creado se convierte en el primer elemento
	if (inicio == nullptr)
		inicio = nuevo;
	else {                      // Si ya existen elementos en la lista, entonces necesitamos
		nodo<T>* aux = inicio;     // un auxiliar para recorrer la lista y colocarnos al final
		while (aux->getSig() != nullptr)
			aux = aux->getSig();
		aux->setSig(nuevo);   // El último nodo apunta al nodo nuevo
		nuevo->setAnt(aux);   // Apuntamos al nodo anterios
	}
	cantnodos++;
}

template<class T>
inline void lista_doble_enlazada<T>::borrar_inicio()
{
	actual = inicio;
	if (inicio != nullptr)
	{
		inicio = actual->getSig();
		inicio->setAnt(NULL);
		delete actual;
	}
	cantnodos--;
}

template<class T>
inline void lista_doble_enlazada<T>::borrar_final()
{
	if (inicio != NULL and inicio->getSig() == nullptr)
	{
		delete inicio;
		inicio = nullptr;
	}
	else
	{
		actual = inicio;
		while (actual->getSig() != NULL)
			actual = actual->getSig();
	}
	delete actual->getSig();
	actual->setSig(NULL);

}

template<class T>
inline T* lista_doble_enlazada<T>::buscar_elemento(T& dato)
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

template<class T>
inline bool lista_doble_enlazada<T>::borrar_elemento(T& dato)
{

	actual = inicio;

	if (actual->getPtr() == &dato)
	{
		inicio = inicio->getSig();
		inicio->setAnt(nullptr);
		delete actual;
		actual = nullptr;
		cantnodos--;
		return true;
	}
	else {
		nodo<T>* anterior = NULL;
		// hay buscarlo entre la lista
		while (actual->getPtr() != &dato and actual->getSig() != NULL)
		{
			anterior = actual;
			actual = actual->getSig();
		}

		if (actual->getPtr() == &dato and actual->getSig() == NULL) {//encontrado , y si es el ultimo
			anterior->setSig(nullptr);
			delete actual; cantnodos--;
			return true;
		}
		if (actual->getPtr() == &dato and actual->getSig() != NULL)// si esta por el medio
		{
			nodo<T>* aux = actual->getSig();
			anterior->setSig(aux);
			aux->setAnt(anterior);
			delete actual;
			actual = nullptr;
			cantnodos--;
			return true;
		}
		else
			return false;
	}
}


template<class T>
inline bool lista_doble_enlazada<T>::borrar_elemento_indice(int indice)
{
	if (inicio == NULL or indice<0 or indice>cantnodos)
		return false;
	else// se encuentra en el rango para buscarlo
	{

		int a = 0;
		imprimir_lista(); actual = inicio;
		nodo<T>* aux = NULL;
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
		else if (a == cantnodos)//borrar el final
		{
			borrar_final();
			return true;
		}
		else//hay que borrar otros
		{
			nodo<T>* aux2 = actual->getSig();
			aux->setSig(aux2);
			aux2->setAnt(aux);
			delete actual;
			cantnodos--;
			return true;
		}

	}
}

template<class T>
inline bool lista_doble_enlazada<T>::imprimir_lista()
{
	nodo<T>* aux = inicio; int a = 0;
	cout << "NUMERO DE ELEMENTOS : " << cantnodos << "." << endl;

	if (aux != nullptr)
	{

		cout << "-------Mostrando los Datos--------" << endl;
		while (aux != NULL)
		{
			cout << "N" << a++ << ". " <<
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

template<class T>
inline bool lista_doble_enlazada<T>::imprimir_lista_invertida()
{

	if (es_vacia()) {
		return false;
	}
	else
	{
		nodo<T>* aux;
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

template<class T>
inline void lista_doble_enlazada<T>::detalles()
{
	nodo<T>* aux = inicio;

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



template<class T>
inline bool lista_doble_enlazada<T>::es_vacia()
{
	return (inicio == NULL);
}

template<class T>
inline nodo<T>* lista_doble_enlazada<T>::getPrimero()
{
	if (es_vacia() == 0)
		return inicio;
	return NULL;
}
template<class T>
inline nodo<T>* lista_doble_enlazada<T>::getUltimo()
{
	nodo<T>* aux=this->getPrimero();
	while (aux->getSig())
		aux = aux->getSig();

	return aux;
}






#endif  // FOO_BAR_BAZ_H_



////#pragma once
//
//
//// lista_doble_enlazada.h
//// Autor: Gabriel Barboza Carvajal
//// Descripción: clase lista que contiene nodos genericos para su implementacion.
//
//#ifndef LISTA_H_
//#include"nodo.h"
//#define LISTA_H_
//
//template<class T>
//
//class lista {
//
//private:
//
//	nodo<T>* inicio;   // Este es el super importante.
//	nodo<T>* actual;
//	int cantnodos;
//
//public:
//
//	lista();
//	~lista();
//	bool es_vacia();
//	nodo<T>* getPrimero();
//	void insertar_inicio(T*);
//	void insertar_final(T*);
//	bool borrar_inicio();
//	bool borrar_final();
//	T* buscar_elemento(T&);
//	bool borrar_elemento(T&);
//	bool borrar_elemento_indice(int indice);
//	void imprimelista();
//
//
//};
////----------------Definicion de métodos------------------------
//
////-------------------Constructores------------------------------------------
//template<class T>
//lista<T>::lista()
//{
//	inicio = NULL;
//	actual = NULL;
//	cantnodos = 0;
//}
//
//template<class T>
//lista<T>::~lista()
//{
//	actual = inicio;
//
//	while (inicio != NULL)
//	{
//
//		actual = inicio;
//		inicio = inicio->getSig();
//
//		delete actual;
//
//	}
//
//}
//
////-------------------------------Metodos Funcionalidad--------------------------------------------------
//
//template<class T>
//bool lista<T>::es_vacia()
//{
//	if (inicio == NULL) { return true; }
//	return false;
//}
//
//template<class T>
//nodo<T>* lista<T>::getPrimero()
//{
//	if (es_vacia() == 0)
//	{
//		return inicio;
//	}
//	return NULL;
//}
//
//template<class T>
//void lista<T>::insertar_inicio(T* dato)
//{
//
//	nodo<T>* aux = new nodo<T>(dato);// se le asigna el dato
//	aux->setSig(inicio);//se asigna el siguiente nodo
//	inicio = aux;
//	cantnodos++;
//
//}
//
//template<class T>
//inline void lista<T>::insertar_final(T* a)
//{
//	if (inicio == nullptr)
//	{
//		insertar_inicio(a);
//	}
//	else
//	{
//		actual = inicio;
//		while (actual->getSig() != nullptr)
//		{
//			actual = actual->getSig();
//		}
//		nodo<T>* aux = new nodo<T>(a);
//		aux->setSig(NULL);
//		actual->setSig(aux);
//		cantnodos++;
//	}
//}
//
//template<class T>
//inline bool lista<T>::borrar_inicio()
//{
//	actual = inicio;
//	if (inicio != nullptr)
//	{
//		inicio = actual->getSig();
//		delete actual;
//		cantnodos--;
//		return true;
//	}
//	else
//		return false;
//}
//
//template<class T>
//inline bool lista<T>::borrar_final()
//{
//	if (inicio == NULL)
//		return false;
//	else
//	{
//		if (inicio->getSig() == nullptr)
//		{
//			delete inicio;
//			inicio = nullptr;
//			cantnodos--;
//			return true;
//		}
//		else
//		{
//			actual = inicio;
//			while (actual->getSig() != NULL)
//				actual = actual->getSig();
//		}
//		delete actual->getSig(); cantnodos--;
//		actual->setSig(NULL);
//		return true;
//	}
//}
//
//template<class T>
//inline T* lista<T>::buscar_elemento(T& dato)
//{
//	actual = inicio;
//	if (actual->getPtr() == &dato)
//		return actual->getPtr();
//
//	else
//
//		while (actual->getPtr() != &dato and actual->getSig() != NULL)
//			actual = actual->getSig();
//
//	if (actual->getPtr() == &dato) //encontrado
//		return actual->getPtr();
//	else
//		return NULL;
//}
//
//template<class T>
//inline bool lista<T>::borrar_elemento(T& dato)
//{
//	actual = inicio;
//
//	if (actual->getPtr() == &dato)
//	{
//		inicio = inicio->getSig();
//		delete actual; cantnodos--;
//		return true;
//	}
//	else {
//		nodo<T>* anterior = NULL;
//
//		while (actual->getPtr() != &dato and actual->getSig() != NULL)
//		{
//			anterior = actual;
//			actual = actual->getSig();
//		}
//
//		if (actual->getPtr() == &dato and actual->getSig() == NULL) {//encontrado , y si es el ultimo
//			anterior->setSig(nullptr);
//			delete actual; cantnodos--;
//			return true;
//		}
//		if (actual->getPtr() == &dato and actual->getSig() != NULL)// si esta por el medio
//		{
//			anterior->setSig(actual->getSig());
//			delete actual; cantnodos--;
//			return true;
//		}
//		else
//			return false;
//	}
//}
//
//template<class T>
//inline bool lista<T>::borrar_elemento_indice(int indice)
//{
//	if (inicio == NULL or indice<0 or indice>cantnodos)
//		return false;
//	else// se encuentra en el rango para buscarlo
//	{
//
//		int a = 0;
//		imprimelista(); actual = inicio;
//		nodo<T>* aux = NULL;
//		while (a != indice and actual->getSig() != nullptr)
//		{
//			aux = actual;
//			actual = actual->getSig();
//			a++;
//		}
//		if (a != 0)
//			cout << *(aux->getPtr()) << endl;
//		if (a == 0)//hay que eliminar el primero
//		{
//
//			borrar_inicio();
//			return true;
//		}
//		else if (a == cantnodos)//borrar el final
//		{
//
//			borrar_final();
//			return true;
//		}
//		else//hay que borrar otros
//		{
//
//			aux->setSig(actual->getSig());
//			delete actual;
//			cantnodos--;
//			return true;
//		}
//
//	}
//}
//
//template<class T>
//void lista<T>::imprimelista()
//{
//	actual = inicio;
//	int a = 0;
//	cout << "NUMERO DE ELEMENTOS : " << cantnodos << "." << endl;
//	if (es_vacia() == 0)
//	{
//
//		while (actual != NULL)
//		{
//			cout << "N" << a++ << ". " <<
//				*actual->getPtr() << endl;// si es un contenedor de personas , hay que sobrecargar el operador de salida
//			actual = actual->getSig();
//		}
//
//	}
//	else {
//		cout << "la lista esta vacia " << endl;
//	}
//
//	cout << "-----------------Fin de la Impresion------------------------------" << endl;
//	cout << endl << endl;
//}
//
//
//
//
//
//#endif  // FOO_BAR_BAZ_H_