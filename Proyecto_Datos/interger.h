#ifndef INTERGER_H_

#define INTERGER_H_
#include"lista.h"
#include"vector.h"
#include<string>
#include<iostream>
#include<fstream>
#include"cadena.h"
#include"utiles.h"
using namespace std;
class interger{

private:

	lista_doble_enlazada* lis;
	int cantidad_nodos;
	long pos;
	int hola;
	int cont;
public:

	interger();
	
	~interger();


	int obtener_cantidad_nodos();

	string operator[](long pos);

	long obtener_numero_digitos() {
		return obtener_cantidad_nodos() * 16;
	}

	operator int()
	{
		return hola;
	}

	//Sobrecarga de operadores de comparacion
	bool operator==(interger num2);
	bool operator!=(interger num2);
	bool operator>(interger num2);
	bool operator<(interger num2);
	bool operator>=(interger num2);
	bool operator<=(interger num2);
	//------------------------------------

	void mostrarNumero();
	void mostrar_resultado_numero_multi();
	void mostrarNumeroRellenandoOs();
	void mostrarNumeroAComoSeAlmacena();
	void ConvertirObjeto(string s1);

	//--------------------METODO PARA GUARDAR EL INTERGER EN UN TXT-------------------

	string toString();

	void guardar_numero_txt(string nombre_archivo);
	void cargar_numero(string nombre_archivo);

	int digitos_numero();

	vector* obtener_nodo(int pos);


	//------------------------------------multiplicacion de intergers-----------------------------------------------

//-------------------------- __________M O D I F I C A C I O N ___ P A R A ___ I N T E R G E R S _____-----------------------------
	int getCarry(int num) {
		int carry = 0;
		if (num >= 10) {
			while (num != 0) {
				carry = num % 10;
				//cout << "Carry : " << carry << endl;
				num = num / 10;
				//cout << "Num : " << num << endl;
			}
		}

		else {
			carry = 0;
			/*	cout << "Num <= 10" << endl;
				cout << "Carry : " << carry << endl;
				cout << "Num : " << num << endl;*/
		}
		return carry;
	}

	//convierte un caracter a un entero


	//----------------> anterior no recupera al 100% , abajo esta la version corregida
	//interger* mult(interger intera, interger interb) {

	//	cadena ret(intera.obtener_numero_digitos() + interb.obtener_cantidad_nodos());
	//	int a_len = intera.obtener_numero_digitos();// para obtener los valores para recorrer el ciclo
	//	int b_len = interb.obtener_numero_digitos();

	//	//--------------guardamos el numero del interA en el txt , para que cadena a , lo carge...
	//	string nombre_archi_interA = "../intergerA.txt";
	//	intera.guardar_numero_txt(nombre_archi_interA);

	//	//--------------guardamos el numero del interB en el txt , para que cadena a , lo carge...
	//	string nombre_archi_interB = "../intergerB.txt";
	//	interb.guardar_numero_txt(nombre_archi_interB);

	//	cadena a(1);//para cargar los valores del intera 

	//	a.cargar_informacion(nombre_archi_interA);

	//	cadena b(1);//para cargar los calores del interb

	//	b.cargar_informacion(nombre_archi_interB);

	//	cout << "cadena 1: ";
	//	a.mostrarCadena();
	//	cout << "cadena 2: ";
	//	b.mostrarCadena();

	//	//las dos cadenas tienen la informacion de cada interger


	//	/*
	//	cout << "Tamanio de " << a << " = " << a_len << endl;
	//	cout << "Tamanio de " << b << " = " << b_len << endl;*/
	//	int  overflow = 2;
	//	int  row = b_len;
	//	int  col = a_len + b_len + overflow;
	//	cout << "Filas : " << row << endl;
	//	cout << "Columnas : " << col << endl;
	//	// se crea una matriz del tamaño del primer numero el numero de filas.
	//	// y las columnas con la del segundo numero.
	//	//esta matriz si tendria que ser de un tipo establecido
	//	//las cadenas si se podrian cambiar por un objeto de tipo interger...
	//	/*int** mat = new int* [row];// vamos a intentarlo hacer pero de tipo short para mejorar el espacio
	//	for (int i = 0; i < row; i++)
	//	{
	//		mat[i] = new int[col];
	//	}
	//	for (int i = 0; i < row; ++i) {
	//		for (int j = 0; j < col; ++j) {
	//			mat[i][j] = 0;

	//		}
	//	}*/
	//	short** mat = new short* [row];
	//	for (int i = 0; i < row; i++)
	//	{
	//		mat[i] = new short[col];
	//	}
	//	for (int i = 0; i < row; ++i) {
	//		for (int j = 0; j < col; ++j) {
	//			mat[i][j] = 0;

	//		}
	//	}
	//	//fin creacion de la matriz

	//	int carry = 0, n, x = a_len - 1, y = b_len - 1;
	//	// x es igual a la cantidad de digitos del primer numero -1 
	//	// y es igual a la cantidad de digitos del segundo numero -1

	//	//recorremos las filas
	//	for (int i = 0; i < row; ++i) {
	//		x = a_len - 1;
	//		//cout << "x : " << x << endl;
	//		carry = 0;
	//		//recorremos las columnas de derecha a izquierda
	//		for (int j = (col - 1) - i; j >= 0; --j) {
	//			//se verifica que la cantidad de digitos del primer y segundo numero sean mayores a 0
	//			//cout << "x : " << x << endl;
	//			if ((x >= 0) && (y >= 0)) {

	//				//multiplica el ultimo numero del segundo numero con el ultimo del primer numero
	//				//como se hace a pie , como se aprende en la escuela
	//				//

	//				//podriamos multiplicar un short de 4 digitos por otro short de 4 digitos y almacenar el valor en un int
	//				n = (num(a[x]) * num(b[y])) + carry;/*
	//				cout << "Carry : " << carry << endl;
	//				cout << "num(a) : " << num(a[x]) << " x " << "num(b) : " << num(b[y]) << " = " << n << endl;*/
	//				mat[i][j] = n % 10;// podriamos quitar los equivalentes a usar 8 - 9 digitos de una vez , por que aqui
	//				//solamentes se usan 2 digitos por posicion de la matriz...
	//				//ver este asunto a ver que
	//				/*cout << "mat[ " << i << " ] " << "[ " << j << " ] " << mat[i][j] << endl;
	//				cout << "-----------------------------------------------------------------------------------" << endl;
	//				cout << "--------------- I M P R E S I O N ___  DE __ LA __ M A T R I Z ----------------------" << endl;

	//				for (int i = 0; i < row; ++i) {
	//					for (int j = 0; j < col; ++j) {

	//						cout << " [ " << mat[i][j] << " ] ";

	//					}
	//					cout << endl;
	//				}*/


	//				carry = getCarry(n);
	//				/*cout << "Carry : " << carry << endl;
	//				cout << "-----------------------------------------------------------------------------------" << endl;
	//				system("pause");*/
	//			}
	//			else if ((x >= -1) && (y >= -1)) {
	//				mat[i][j] = carry;
	//				/*			cout << "mat[ " << i << " ] " << "[ " << j << " ] " << mat[i][j] << endl;

	//							cout << "-----------------------------------------------------------------------------------" << endl;
	//							cout << "--------------- I M P R E S I O N ___  DE __ LA __ M A T R I Z ----------------------" << endl;

	//							for (int i = 0; i < row; ++i) {
	//								for (int j = 0; j < col; ++j) {

	//									cout << " [ " << mat[i][j] << " ] ";

	//								}
	//								cout << endl;
	//							}
	//							cout << "-----------------------------------------------------------------------------------" << endl; system("pause");
	//					*/
	//			}
	//			x = x - 1;
	//		}
	//		y = y - 1;
	//	}


	//	//cout << "--------------- I M P R E S I O N ___  DE __ LA __ M A T R I Z ----------------------" << endl;

	//	//for (int i = 0; i < row; ++i) {
	//	//	for (int j = 0; j < col; ++j) {
	//	//		
	//	//		cout << " [ " << mat[i][j] << " ] ";

	//	//	}
	//	//	cout << endl;
	//	//}

	//	//cout << "----------------------------------------------------------------------------------------" << endl;


	//	//cout << "_----------------------------------- O T R O ___ M O D U L O _----------------------------" << endl;
	//	carry = 0;
	//	//se agrega el valor de la matriz en el arreglo
	//	int* sum_arr = new int[col];
	//	for (int i = 0; i < col; ++i) sum_arr[i] = 0;
	//	for (int i = 0; i < row; ++i) {
	//		for (int j = col - 1; j >= 0; --j) {
	//			sum_arr[j] += (mat[i][j]);
	//			//cout << "sum_arr " << sum_arr[j] << endl;
	//		}
	//	}


	//	/*
	//		cout << "----------------------------------------------------------------------------------------" << endl;

	//		cout << "_----------------------------------- O T R O ___ M O D U L O  2 _----------------------------" << endl;*/
	//	int temp;
	//	//se suma el contenido de la matriz
	//	for (int i = col - 1; i >= 0; --i) {
	//		//cout << "sum_arr[" << i << " ] = " << sum_arr[i] << " , Carry = " << carry << endl;
	//		sum_arr[i] += carry;
	//		//cout << "sum_arr[" << i << " ] = " << sum_arr[i] << " , Carry = " << carry << endl;
	//		temp = sum_arr[i];
	//		//cout << "Temp = " << temp << endl;
	//		sum_arr[i] = sum_arr[i] % 10;
	//		//cout << "sum_arr[" << i << " ] = " << sum_arr[i] << endl;
	//		carry = getCarry(temp);
	//		//cout << "Carry : " << carry << endl;
	//	}

	//	//cout << "-----------------------------------------------------------" << endl;
	//	for (int i = 0; i < col; ++i) {
	//		//ret.push_back(char(sum_arr[i] + 48));
	//		ret.Insertar(char(sum_arr[i] + 48));
	//		//cout << ret[i] <<" , ";
	//	}
	//	/*
	//		while (ret[0] == '0') {
	//			ret = ret.substr(1, ret.length() - 1);
	//		}*/

	//	cout << "resultado : ";
	//	ret.mostrarCadena();

	//	string nom_resul = "../resultado_interger.txt";
	//	ret.guardar_resultado(nom_resul);

	//	interger* resultado = new interger();

	//	resultado->cargar_numero(nom_resul);

	//	return resultado;
	//}
int num(char a) {
	return int(a) - 48;
}
int num(string a) {
	return atoi(a.c_str());
}


interger* multiply(interger num1, interger  num2)
{
	int len1 = num1.obtener_numero_digitos();
	int len2 = num2.obtener_numero_digitos();
	if (len1 == 0 || len2 == 0)
		return nullptr;


	// will keep the result number in vector 
	// in reverse order 
	//vector<int> result(len1 + len2, 0);
	//cadena result(len1 + len2);
	short* result = new short[len1 + len2];
	for (size_t i = 0; i < len1 + len2; i++)
	{
		result[i] = 0;
	}
	// Below two indexes are used to find positions 
	// in result.  
	int i_n1 = 0;
	int i_n2 = 0;
	// Go from right to left in num1 
	for (int i = len1 - 1; i >= 0; i--)
	{
		cout << "i :" << i << endl;
		int carry = 0;
		int n1 = num(num1[i]);
		//cout << "n1 : " << n1 << endl;
		// To shift position to left after every 
		// multiplication of a digit in num2 
		i_n2 = 0;

		// Go from right to left in num2              
		for (int j = len2 - 1; j >= 0; j--)
		{
			// Take current digit of second number 
			int n2 = num(num2[j]);
			//cout << "n2 : " << n2 << endl;
			// Multiply with current digit of first number 
			// and add result to previously stored result 
			// at current position.  
			int sum = n1 * n2 + result[i_n1 + i_n2] + carry;

			// Carry for next iteration 
			carry = sum / 10;

			// Store result 
			//result[i_n1 + i_n2] = sum % 10;
			result[i_n1 + i_n2] = sum % 10;
			i_n2++;
		}

		// store carry in next cell 
		if (carry > 0)
			result[i_n1 + i_n2] += carry;

		// To shift position to left after every 
		// multiplication of a digit in num1. 
		i_n1++;
	}

	// ignore '0's from the right 
	int i = (len1 + len2) - 1;
	//cout << " i : " << i << endl;
	while (i >= 0 && result[i] == 0)
		i--;

	// If all were '0's - means either both or 
	// one of num1 or num2 were '0' 
	if (i == -1)
		return nullptr;

	//// generate the result string 
	string s = "";
	//guardamos el resultado en un txt

	while (i >= 0)
		s += std::to_string(result[i--]);

	cadena* resu = new cadena(0);

	i = (len1 + len2) - 1;
	//cout << " i : " << i << endl;
	while (i >= 0)
	{
		string ss = std::to_string(result[i--]);
		//cout << "ss : " << ss << endl;
		resu->Insertar(ss.at(0));
		ss = "";
	}

	//cout << "resultado : " << s << endl;
	//cout << "Resul cadena : \n";
	//resu->mostrarCadena();
	resu->guardar_resultado("../resultado.txt");
	resu->guardar_resultado_alreves("../resultado_alreves.txt");
	interger* res = new interger();
	//res->cargar_numero("../resultado.txt");
	res->cargar_numero_alreves("../resultado_alreves.txt");
	return res;
	//return s;
}

void cargar_numero_alreves(string nombre_archivo);
};

#endif INTERGER_H_