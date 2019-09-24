
#include"interger.h"

int main()
{

/*
	int a = 99999999;
	int b = 99999999;

	int r = a * b;
	cout << r << endl;
	cout << r % 10 << endl;
	cout << r / 10 << endl;*/

	////
	interger in1;
	//////   0123   4567  8-11   12-16     17-20  21-24  25-28   29-32
 ////	//" [1234] [5678] [9101] [1129] -> [3141] [5161] [71819] [2021] -> ";
	string s = "12345678912345678";
	////			
	in1.ConvertirObjeto(s);
	//interger in2;

	//in2.ConvertirObjeto(s);


	cout << "numero de nodos : " << in1.obtener_cantidad_nodos() << endl;
	cout << "numero de digitos : " << in1.obtener_numero_digitos() << endl;

	//cout << "---------------------------------------------" << endl;
	cout<<in1.toString()<<endl;
	cout << "---------------------------------------------------" << endl;
	for (size_t i = 0; i < in1.obtener_numero_digitos(); i++)
	{
		cout << "i = "<<i<<" ->"<< in1[i] << endl;
	}
	cout << "---------------------------------------------------" << endl;



	//cout << "---------------------------------------------------" << endl;

	//cout << "---------------------------------------------------" << endl;
	//cout << "---------------------------------------------------" << endl;
	//int num=32;
	//cout << "Digite el la posicion de su digito" << endl;
	////cin >> num;
	//cout<<in1[num]<<endl;
	//cout << "numero : toString()" << endl;
	//cout << in1.toString() << endl;
	in1.guardar_numero_txt();

	/*cout << endl << "_-------------------------------------------------" << endl;
	cout << "_---------MOSTRANDO NUMERO EN LA MANERA EN LA QUE SE ALMACENA-------------------" << endl << endl;
	in1.mostrarNumeroRellenandoOs();
	cout << endl << endl;
	cout << endl << "_-------------------------------------------------" << endl;
	cout << "_---------MOSTRANDO NUMERO EN LA MANERA EN LA QUE SE ALMACENA sin Os-------------------" << endl << endl;
	in1.mostrarNumeroAComoSeAlmacena();
	cout << endl << endl;*/
	/*
		vector v;

		v.insertarElementoFinal(0000);
		v.insertarElementoFinal(1234);

		cout << v.toString();*/

	system("pause");
	return 0;
}