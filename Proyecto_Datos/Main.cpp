#include"interger.h"

int main()
{
	//A partir de 10 digitos ya sirve 
	interger in1;
	in1.ConvertirObjeto("4564654654545464646546546546546546546546544464648");
	//
	interger in2;
	in2.ConvertirObjeto("4564654654545464646546546546546546546546544464648");
	//
	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
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