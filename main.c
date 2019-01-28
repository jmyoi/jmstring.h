#include <stdio.h>
#include "jmstring.h"

int main(int argc, char **argv)
{
	string *a = newstr("Hello");
	if(a == NULL)
	{
		printf("null\n");
	}
	else
	{
		printf("\n");
		printf("string  : %s\n", a->str);
		printf("c_str   : %s\n", c_str(a));
		printf("size    : %d\n", size(a));
		printf("length  : %d\n", length(a));
		printf("capacity: %d\n", capacity(a));
		printf("\n");

		assign(a, "HELLO WORLD");
		printf("string  : %s\n", a->str);
		printf("c_str   : %s\n", c_str(a));
		printf("size    : %d\n", size(a));
		printf("length  : %d\n", length(a));
		printf("capacity: %d\n", capacity(a));
		printf("\n");

		assign(a, "Myoi");
		printf("string  : %s\n", a->str);
		printf("c_str   : %s\n", c_str(a));
		printf("size    : %d\n", size(a));
		printf("length  : %d\n", length(a));
		printf("capacity: %d\n", capacity(a));
		printf("\n");

		free(a->str);
		free(a);
	}

	return 0;
}
