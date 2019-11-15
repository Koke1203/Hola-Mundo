//main.cpp
//Autores: Gabriel Barboza, Jorge Canales y Joan Corea
//Descripcion: 
#include "Validation.h"

// se adjuntan txt's con el formato respectivo para la prueba del sistema

int main() {
	Tools tool;
	SymbolTable tabla;

	//leemos el archivo----------------------------------
	string archivo[MAX];
	string linea;
	ifstream fin("program.txt");
	if (!fin.is_open()) {
		cout << "Error al abrir el archivo \n";
		exit(0);
	}
	int j = 0;
	while (getline(fin, linea)) {
		archivo[j] = linea;
		j++;
	}
	//----------------------------------------------------

	//algunas veces ocupamos todo el contenido del txt en un solo string
	linea = "";  //limpiamos el contenido de 'linea' para reutilizar la variable
	for (int i = 0; i < j; i++) {
		linea += archivo[i] + "\n"; //lo almacenamos en linea
	}

	//Analizadores.....................................
	if (!tool.ValidaParentesis(linea)){
		cout << "Error: Parentesis con problemas de cierre o apertura" << endl;
	}

	//valida si una variable esta declarada o no
	validaVariable(archivo, tool, tabla);
	//valida que la declaracion de una variable sea correcta
	string nombre_archivo = "program.txt";
	vector<info_linea> vec = vector_sentencias(nombre_archivo);
	mostrar_errores_asignacion(vec);

	funcionRetorno(archivo);
	//..............................................

	cout << endl;

	return 0;
}