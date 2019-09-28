#include"interger.h"

int main()
{
	//A partir de 10 digitos ya sirve 
	interger in1;
	in1.ConvertirObjeto("45474554");
	//
	interger in2;
	in2.ConvertirObjeto("45474554");
	//
	cout << endl << endl << endl ;
	//
	if (in1 == in2) {
		cout << "Son iguales" << endl;
	}
	else {
		cout << "FALSE" << endl;
	}

	system("pause");
	return 0;
}
