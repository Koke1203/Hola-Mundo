#include"cadena.h"


// Inicializa un cadena de tamaño t - todos los valores en cero
cadena::cadena(int t) : v{ nullptr }, capacidad{ t }, tam{ 0 } {
	v = new char[capacidad];

	for (int i = 0; i < capacidad; ++i)
		v[i] = '0';
}

// Constructor de copia
cadena::cadena(const cadena& val) {
	this->capacidad = val.capacidad;
	this->tam = val.tam;

	this->v = new char[capacidad];

	for (int i = 0; i < capacidad; ++i)
		this->v[i] = val.v[i];
}

//Destructor
cadena::~cadena() {
	Eliminarcadena();
}


// Inserta un nuevo valor en el cadena
void cadena::Insertar(char valor) {
	int pos;
	cout << "insertando -> " << tam << endl;
	// Si sobrepasamos la capacidad del vector, incrementamos su tamaño
	if (tam == capacidad)
		Extender();

	// Obtenemos la última posición del vector
	pos = tam++;

	v[pos] = valor;
}

// Elimina el cadena completamente
void cadena::Eliminarcadena() {
	delete v;
	v = nullptr;
	capacidad = 0;
	tam = 0;
}

void cadena::mostrarCadena()
{
	for (size_t i = 0; i < tam; i++)
	{
		cout << (short)(v[i]) - 48;
	}
	cout << endl;
}


void cadena::cargar_informacion(string nombre_archivo)
{
	ifstream entrada = ifstream(nombre_archivo);
	char dato;
	string num;
	while (entrada.good())
	{
		if (!entrada.eof())
			entrada >> dato;
		else
			break;


		this->Insertar(dato);//cargamos el vector con los datos
		dato = '0';
	}
	entrada.close();

}

void cadena::guardar_resultado(string nombre_archivo)
{
	ofstream entrada = ofstream(nombre_archivo);

	for (size_t i = 0; i < this->getTam(); i++)
	{
		entrada << (short)(v[i]) - 48;
	}
	entrada.close();
}

// Extiende el tamaño del cadena
void cadena::Extender() {
	char* tmp = v;
	v = new char[capacidad + 10];

	for (int i = 0; i < capacidad; ++i)
		v[i] = tmp[i];

	capacidad += 10;
	delete tmp;
}