
#include"interger.h"

int main()
{

	interger in1;
	in1.ConvertirObjeto("123456789");
	interger in2;
	in2.ConvertirObjeto("123456789");

	interger *res=NULL;

	res = res->mult(in1, in2);

	cout << ".--------------------." << endl;
	cout << res->toString() << endl;

	system("pause");
	return 0;
}