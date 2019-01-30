#include <stdio.h>
#include "jmstring.h"

int main(int argc, char **argv)
{
	string *a = _new("Hello");

	if(a == NULL)
	{
		printf("null\n");
	}
	else
	{
		_assign(a, "HELLO WORLD");
		printf("string  : %s\n", a->str);
		printf("c_str   : %s\n", c_str(a));
		printf("size    : %d\n", _size(a));
		printf("length  : %d\n", _length(a));
		printf("capacity: %d\n", _capacity(a));
		printf("at: %c\n", _at(a, 1));
		printf("front: %c\n", _front(a));
		printf("back: %c\n", _back(a));
		printf("\n");

		_resize(a, 5);
		printf("resize(5): %s\n", a->str);
		printf("length  : %d\n", _length(a));
		printf("capacity: %d\n", _capacity(a));
		printf("\n");

		_resize(a, 7, "+");
		printf("resize(7): %s\n", a->str);
		printf("length  : %d\n", _length(a));
		printf("capacity: %d\n", _capacity(a));
		printf("\n");

		_resize(a, 6, "+");
		printf("resize(6): %s\n", a->str);
		printf("length  : %d\n", _length(a));
		printf("capacity: %d\n", _capacity(a));
		printf("\n");

		_reserve(a, 18);
		printf("string  : %s\n", a->str);
		printf("length  : %d\n", _length(a));
		printf("capacity: %d\n", _capacity(a));
		printf("\n");

		_shrink_to_fit(a);
		printf("string  : %s\n", a->str);
		printf("length  : %d\n", _length(a));
		printf("capacity: %d\n", _capacity(a));
		printf("\n");


		_push_back(a, 'm');
		_push_back(a, 'y');
		_push_back(a, 'o');
		_push_back(a, 'i');
		printf("string  : %s\n", a->str);
		printf("length  : %d\n", _length(a));
		printf("capacity: %d\n", _capacity(a));
	}

	
	_free(a);

	return 0;
}
