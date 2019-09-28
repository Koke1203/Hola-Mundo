#include "vector.h"

vector::vector()
{
	tamanio = TAM;
	cantidad = 0;

	vec = new short[tamanio];

	for (short i = 0; i < tamanio; i++)
	{
		vec[i] = 0;
	}

}

vector::vector(const vector& vect, bool)
{

	tamanio = vect.tamanio;
	cantidad = vect.cantidad;
	vec = new short[vect.tamanio];
	cout << "--------------------IMPRIMIENDO DEL VECTOR RECIBIDO---------------------------" << endl;
	for (short i = tamanio - 1; i >= 0; i--)
		cout << vect.vec[i] << " , ";

	cout << endl;
	//system("pause");
	for (short i = tamanio - 1; i >= 0; i--)
	{
		if (vect.vec[i] == 0)
			vec[i] = 0;
		else
			vec[i] = vect.vec[i];
	}
	/*for (short i = vect.tamanio - 1 - vect.cantidad; i >= 0; i--)
	{
		vec[i] = 0;
	}*/


}
vector::vector(const vector& vect)
{

	tamanio = vect.tamanio;
	cantidad = vect.cantidad;
	vec = new short[vect.tamanio];
	cout << "--------------------IMPRIMIENDO DEL VECTOR RECIBIDO---------------------------" << endl;
	for (short i = tamanio - 1; i >= vect.tamanio - vect.cantidad; i--)
		cout << vect.vec[i] << " , ";

	cout << endl;
	//system("pause");
	for (short i = tamanio - 1; i >= vect.tamanio - vect.cantidad; i--)
	{
		if (vect.vec[i] == 0)
			vec[i] = 0;
		else
			vec[i] = vect.vec[i];
	}
	for (short i = vect.tamanio - 1 - vect.cantidad; i >= 0; i--)
	{
		vec[i] = 0;
	}


}

vector::~vector()
{
	delete[]vec;
}

vector& vector::operator=(const vector& a2)
{
	//Sobrecarga del operador de asignacion.
	cout << "Coleccion & Coleccion::operator=(const Coleccion & )" << endl;
	if (this != &a2) {
		cout << "Realizar la asignacion" << endl;
		delete[] vec; //Borrar el vector que esta en la coleccion izquierda.
		cantidad = a2.cantidad;
		tamanio = a2.tamanio;
		vec = new short[a2.tamanio];
		for (short i = 0; i < a2.tamanio; i++)
		{
			vec[i] = 0;
		}
		//Terminar de pasar los elementos entre los vectores.
		for (int i = 0; i < a2.cantidad; i++)
			vec[i] = a2.vec[i];
	}
	return *this; //Retornar una referencia es un *this.
}

vector* vector::operator=(const vector* a2)
{

	//cout << "Coleccion & Coleccion::operator=(const Coleccion & )" << endl;
	if (this != a2) {
		//cout << "Realizar la asignacion" << endl;
		delete[] vec; //Borrar el vector que esta en la coleccion izquierda.
		cantidad = a2->cantidad;
		tamanio = a2->tamanio;
		vec = new short[a2->tamanio];
		for (short i = 0; i < a2->tamanio; i++)
		{
			vec[i] = 0;
		}
		//Terminar de pasar los elementos entre los vectores.
		for (int i = 0; i < a2->cantidad; i++)
			vec[i] = a2->vec[i];
	}
	return this; //Retornar una referencia es un *this.
}

short vector::getCuarto()
{
	return vec[3];
}

short vector::getTercero()
{
	return vec[2];
}

short vector::getSegundo()
{
	return vec[1];
}

short vector::getPrimero()
{
	return vec[0];
}

short vector::getTam()
{
	return tamanio;
}

void vector::setCuarto(short a)
{
	vec[3] = a;
}

void vector::setTercero(short a)
{
	vec[2] = a;
}

void vector::setSegundo(short a)
{
	vec[1] = a;
}

void vector::setPrimero(short a)
{
	vec[0] = a;
}

void vector::borrarElementos()
{
	cantidad = 0;
	/*
		for (short i = 0; i < tamanio; i++)
			delete vec[i];
	*/
	delete[]vec;
	vec = new short[tamanio];
	for (short i = 0; i < tamanio; i++)
		vec[i] = 0;


}

bool vector::insertarElementoPrimero(short i)
{
	bool a = false;
	// 0 , 1 , 2 , 3

	// 3 , 2 , 1 , 0

	if (cantidad < tamanio)
	{
		//cantidad++;
		vec[cantidad++] = i;

		a = true;
	}

	return a;
}

bool vector::insertarElementoFinal(short i)
{
	bool a = false;
	short aux = tamanio;
	if (cantidad < tamanio)
	{
		vec[(tamanio - 1) - cantidad] = i;
		cantidad++;
		a = true;
	}

	return a;
}

bool vector::insertar_conforme_se_llena(short i)
{
	return false;
}

void vector::mostrarRellenandoOs()
{
	cout << " { ";
	for (short i = 0; i < tamanio; i++)
	{
		cout << " [ ";
		stringstream s; s << vec[i];
		//cout << "size = " << s.str().size() << endl;
		if (s.str().size() < 4)//para verificar el tamaño de este numero
		{
			for (size_t i = 0; i < 4 - s.str().size(); i++)
				cout << "0";
			cout << vec[i];
		}
		else
			cout << vec[i] << "";
		cout << " ] ";
		s << "";
		//s.clear();
	}
	cout << " } ";
}

void vector::mostrarAlreves()
{
	cout << " [ ";
	for (short i = 3; i >= 0; i--)
		cout << vec[i] << "";
	cout << " ] ";
	//cout << endl << endl;
}


void vector::mostrarNormal()
{
	cout << " [ ";
	for (short i = 0; i < 4; i++)
		cout << vec[i] << "";
	cout << " ] ";
	//cout << endl << endl;
}

void vector::mostrarNormalCasillas() {
	cout << " { ";
	for (short i = 0; i < tamanio; i++)
	{
		cout << " [ ";
		cout << vec[i] << "";
		cout << " ] ";
	}cout << " } ";
	//cout << endl << endl;
}

string vector::retornar_numero_0s()
{
	stringstream num;

	for (short i = 0; i < tamanio; i++)
	{
		stringstream s; s << vec[i];
		//cout << "size = " << s.str().size() << endl;
		if (s.str().size() < 4)//para verificar el tamaño de este numero
		{
			for (size_t i = 0; i < 4 - s.str().size(); i++)
				num << "0";

			num << vec[i];
		}
		else
			num << vec[i];

		//s << "";
		s.clear();
	}
	return num.str();
}

int vector::obtener_cantidad_digitos(short num)
{
	stringstream s;
	s << num;
	return s.str().size();
}

string vector::toString()
{
	stringstream todo_numero;
	//cout << " { ";
	for (short i = 0; i < tamanio; i++)
	{
		//cout << " [ ";
		stringstream s; s << vec[i];

		//cout << "size = " << s.str().size() << endl;
		if (s.str().size() < 4)//para verificar el tamaño de este numero
		{
			for (size_t i = 0; i < 4 - s.str().size(); i++)
			{
				//cout << "0";
				todo_numero << "0";
			}
			//cout << vec[i];
			todo_numero << vec[i];
		}
		else
		{
			//cout << vec[i] << "";
			todo_numero << vec[i];
		}
		//cout << " ] ";
		s << "";
		//s.clear();
	}
	//cout << " } ";
	return todo_numero.str();
}

bool vector::llenando_vector_por_digito(short num)
{
	//ingresamos 4 digitos cada vez que insertamos un num

	return false;
}

ostream& operator<<(ostream& sal, vector& v)
{
	sal << " { ";
	for (int i = 0; i < v.tamanio; i++)
	{
		sal << " [ ";
		sal << v.vec[i];
		sal << " ] ";
	}
	sal << endl;
	return sal;
}
