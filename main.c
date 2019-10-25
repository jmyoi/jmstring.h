#include <stdio.h>
#include <assert.h>

#include "muistring.h"

int main(int argc, char **argv)
{
    String *str = _new("Hello World");

    printf("word      : %s\n", _data(str));
    assert(_size(str) == 11);
    assert(_length(str) == 11);
    assert(_maxsize() == 0xFFFFFFFF);
    assert(_empty(str) == 0);
    _shrink_to_fit(str);
    assert(_capacity(str) == 11);
    assert(_reserve(str, 10) == NULL);
    _reserve(str, 15);
    assert(_capacity(str) == 15);

    _clear(str);

    printf("word      : %s\n", _data(str));
    assert(_data(str) == NULL);
    assert(_size(str) == 0);
    assert(_length(str) == 0);
    assert(_maxsize() == 0xFFFFFFFF);
    assert(_empty(str) == 1);
    _shrink_to_fit(str);
    assert(_capacity(str) == 0);
    assert(_reserve(str, 0xFFFFFFFF + 1) == NULL);
    _reserve(str, 20);
    assert(_capacity(str) == 20);
    _resize(str, 15);
    assert(_length(str) == 15);
    assert(_capacity(str) == 20);

    _clear(str);

    _setstr(str, "I love coding");
    printf("word      : %s\n", _data(str));
    assert(*(_front(str)) == 'I');
    assert(*(_back(str)) == 'g');
    assert(_length(str) == 13);

    _resize(str, 14, " ");
    printf("word      : %s\n", _data(str));
    assert(*(_back(str)) == ' ');
    assert(_length(str) == 14);

    _resize(str, 15, "C");
    printf("word      : %s\n", _data(str));
    assert(*(_back(str)) == 'C');
    assert(_length(str) == 15);

    _resize(str, 17, "+");
    printf("word      : %s\n", _data(str));
    assert(*(_back(str)) == '+');
    assert(_length(str) == 17);

    _resize(str, 13, "+");
    printf("word      : %s\n", _data(str));
    assert(*(_back(str)) == 'g');
    assert(_length(str) == 13);

    assert(_at(str, 0) == 'I');
    assert(_at(str, 4) == 'v');
    assert(_at(str, 5) == 'e');
    assert(_at(str, 20) == '\0');

    free(str);


    return 0;
}
