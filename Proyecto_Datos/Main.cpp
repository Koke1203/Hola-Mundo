#include"interger.h"

int main()
{

	//A partir de 10 digitos ya sirve 
	interger in1;
	in1.ConvertirObjeto("873384448733844987338444");
	//
	interger in2;
	in2.ConvertirObjeto("873384448733844487338444");
	//
	cout << endl;
	//
	if (in1 > in2) {
		cout << " N1 Mayor" << endl;
	}
	else {
		cout << "N1 Menor" << endl;
	}




	system("pause");
	return 0;
}
