// Validation.h
// Autores: Gabriel Barboza, Jorge Canales y Joan Corea
// Descripción: implementacion del compilador, se realizan todas las validaciones

//------------------------------------------------------------------------

#ifndef VALIDATION_H_
#define VALIDATION_H_ 

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <ctype.h>
#include <stack>
#include <sstream>
#include <vector>
#include "symbol_table.h"
#include "tools.h"
#include "info_linea.h"

#define MAX 100
using namespace std;


//valida que uno variable este declarada tomando en cuenta los parametros
void validaVariable(string st[], Tools tool, SymbolTable tabla) {
	for (int i = 0; i < 26;i++) {
		string aux[17];
		stringstream ss(st[i]);
		string palabra;
		int j = 0;
		//para guardar cada palabra en un vector, usamos la funcion stringstream con el operador >>
		while (ss >> palabra) {
			aux[j] = palabra;
			j++;
		}
		//inserto en la tabla de simbolos si el primer elemento es un tipo de variable
		//puedo ser una variable a como tambien puede ser una funcion, lo averiguamos mas adelante
		if (tool.isVariable(aux[0])) {
			//En caso de una variable: 
			//valido que la variable no se encuentre ya registrada en la tabla de simbolos
			if (tabla.buscar(aux[1]) == "0") {
				tabla.insertar(aux[1], "local", aux[0], (i + 1));
			}
			else {  //es porque la variable ya esta declarada y la estan declarando de nuevo
				cout << "Error-Linea " << (i + 1) << ": " << "'" << aux[0] << "' ya esta declarada" << endl;
			}

			int param_aux = 2;
			//En caso de una funcion: recorre todos los parametros
			for (int j = param_aux; j < (param_aux * 6); (j += 3)) {
				if (tool.isVariable(aux[j])) {  //es el tipo del primer parametro
					tabla.insertar(aux[(j + 1)], "parametro", aux[j], (i + 1));
				}
			}
		}

		//es porque hay una variable que no esta declarada
		if (aux[1] == "=") {
			//si ya se encuentra la variable, entonces no tiene que tirar error! Al igual que la funcion (*en teoria*)
			if (aux[3] == "" && tabla.buscar(aux[0]) == "0") {
				//imprimimos el error de declaracion
				cout << "Error-Linea " << (i + 1) << ": " << "'" << aux[0] << "' no esta declarado" << endl;
			}
		}
	}
}

void funcionRetorno(string archivo[]) {
	int cont1 = 0;
	int cont2 = 0;
	int cont3 = 0;
	int parent = 0;
	int poscparent = 0;
	int poscreturn = 0;
	for (int i = 0; i < 20; i++)
	{
		string aux[20];
		stringstream ss(archivo[i]);
		string Word;
		int j = 0;
		while (ss >> Word) {
			aux[j] = Word;
			j++;
		}
		if (aux[2] == "(") {
			cont3 = i;
		}
		if (aux[0] == "void") {
			cont1++;
		}
		if (aux[0] == "return") {
			poscreturn = i;
			cont2++;
		}
		if (aux[0] == "}") {
			poscparent = i;

		}
	}
	if (cont1 == 1 && cont2 == 1 && poscreturn + 1 < poscparent + 1) {
		cout << "Error-Linea " << poscreturn + 1 << ": return en una funcion void" << endl;
	}
	if (cont1 == 1 && cont2 == 1 && poscreturn + 1 > poscparent + 1) {
		cout << "Error-Linea " << poscreturn + 1 << ": return no tiene asociacion con ninguna funcion" << endl;
	}
	if (cont1 == 0 && cont2 == 1 && poscreturn + 1 > poscparent + 1)
	{
		cout << "Error-Linea " << poscreturn + 1 << ": return fuera de las llaves de la funcion" << endl;
	}
	if (cont1 == 0 && cont2 == 1 && poscreturn + 1 < cont3 + 1)
	{
		cout << "Error-Linea " << poscreturn + 1 << ": return fuera de las llaves de la funcion" << endl;
	}
}

//se lee el archivo obteniendo linea por linea
vector<string> leerArchivoPorLinea() {
	vector<string> archivo;
	string linea;
	ifstream fin("program.txt");
	if (!fin.is_open()) {
		cout << "Error al abrir el archivo \n";
		exit(0);
	}
	int j = 0;
	while (getline(fin, linea)) {
		archivo.push_back(linea);
		j++;
	}
	return archivo;
}

//se lee el archivo por medio de una sentencia
vector<info_linea> vector_sentencias(string nombreArchivo)
{
	//abrimos archivo de codigo
	ifstream leer(nombreArchivo);
	string datos;
	vector<info_linea> vec;
	int cont = 0;
	while (!leer.eof())
	{
		getline(leer, datos, '\n');
		if (datos.size() != 0 and datos != "-1")
			vec.push_back(info_linea(datos, cont++));
		else
			cont++;
		datos = "";
	}

	return vec;
}

string verificarValorDeclaradoInt(string lineaDeclaracionInt)
{
	int posIgual = lineaDeclaracionInt.find("=", 0);
	if (posIgual == -1)
		return "-1";
	else
	{
		string datos = "";
		//recorremos desde el igual en adelante....
		if (lineaDeclaracionInt.find('"', 0) != -1)
			return "Comillas no es un valor entero";

		for (int i = posIgual + 1; i < lineaDeclaracionInt.length(); i++)
			if (isalpha(lineaDeclaracionInt[i]))
			{
				return "Letra , int no acepta letras o caracteres alfanumericos";
				break;
			}

	}
	return "-1";
}

string verificarValorDeclaradoString(string lineaDeclaracionInt)
{
	int cont = 0;
	int posIgual = lineaDeclaracionInt.find("=", 0);
	if (posIgual == -1)
		return "-1";
	else
		for (int i = posIgual; i < lineaDeclaracionInt.length(); i++)
			if (lineaDeclaracionInt[i] == '"')
				cont++;

	if (cont != 2)
		return "No hay comillas en la asignacion a string";
	else
		return "-1";
}

string tipoDato(string lineaProcesar)
{
	string tipoDatoLine = "";
	string tipo1 = "int";
	string tipo2 = "string";
	string tipo3 = "float";

	int posDato = lineaProcesar.find(tipo1, 0);
	int posDato1 = lineaProcesar.find(tipo2, 0);
	int posDato2 = lineaProcesar.find(tipo3, 0);

	//si no encontro un tipo int, float o string entonces 
	//no hay declaracion de variable en esta linea.
	if (posDato == -1 and posDato1 == -1 and posDato2 == -1)
		return "-1";
	else {
		if (posDato != -1)// es de tipo int
			tipoDatoLine = verificarValorDeclaradoInt(lineaProcesar);
		if (posDato1 != -1)//es de tipo string
			tipoDatoLine = verificarValorDeclaradoString(lineaProcesar);
		if (posDato2 != -1)//es de tipo float
			tipoDatoLine = verificarValorDeclaradoInt(lineaProcesar);

	}
	return tipoDatoLine;
}

void mostrar_errores_asignacion(vector<info_linea> vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		string info = tipoDato(vec.at(i).get_linea_datos());
		if (info != "-1")
		{
			cout << vec.at(i).obtener_info(info);
		}
	}
}

#endif