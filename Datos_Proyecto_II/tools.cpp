#include "tools.h"



int tools::isKeyword(char buffer[]) {
	char keywords[32][10] = { "void","int","float","string",
							"if","while","return" };
	int i, flag = 0;

	for (i = 0; i < 32; ++i) {
		if (strcmp(keywords[i], buffer) == 0) {
			flag = 1;
			break;
		}
	}
	return flag;
}