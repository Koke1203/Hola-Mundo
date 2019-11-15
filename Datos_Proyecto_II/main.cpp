//main.cpp
//Autores: Gabriel Barboza, Jorge Canales y Joan Corea
//Descripcion: 
#include "Validation.h"

/* 1) Se adjuntan txt's con el formato respectivo para la prueba del sistema
   el primer archivo llamado 'prueba1' contiene el error de que no se declara una variable 
   ademas que se declara otra variable entera pero se le asigna una cadena.
   2) El segundo archivo se llama 'prueba2', contiene los siguientes errores: se declara un string pero se le iguala una cadena,
      ademas que se declara un metodo void y se retorna una variable
   3) El tercer archivo se llama 'prueba3' que no contiene ningun error

   Nota: si no se imprime nada es porque el archivo esta correcto


   A la variable que se le tiene que cambiar el nombre del archivo se llama: 'nombre_archivo'
*/


int main() {
	Tools tool;

	//leemos el archivo----------------------------------
	string archivo[MAX];
	string linea;

	string nombre_archivo = "prueba1.txt";
	
	ifstream fin(nombre_archivo);
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
	
	//valida que la declaracion de una variable sea correcta
	vector<info_linea> vec = vector_sentencias(nombre_archivo);
	mostrar_errores_asignacion(vec);

	//valida si una variable esta declarada o no
	validaVariable(archivo, tool);

	//valida el retorno en las funciones
	funcionRetorno(archivo);
	//..............................................

	//si no hay errores
	if (errores==0) {
		cout << " ***************** " << endl<<endl;
		cout << "Compilacion exitosa." << endl<<endl;
		cout << " ***************** " << endl;
	}

	cout << endl;

	return 0;
}