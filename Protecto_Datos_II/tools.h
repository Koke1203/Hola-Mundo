#ifndef TOOLS_
#define TOOLS_

#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <stack>
#include <string>
using namespace std;

class tools
{
public:
	bool ValidaParentesis(string);
	int isKeyword(string);
	int isOperator(char);
};
#endif  // TOOLS_
