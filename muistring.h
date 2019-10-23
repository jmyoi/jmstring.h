#pragma once

#include <stdlib.h>
#include <stdarg.h>

#define INITIAL_BUFFER 16

typedef struct String
{
	// public
	char *str;

	// this should be private (@TODO: find a way to hide this?)
	const char * beg;    // points to beginning of a string
	const char * end;    // points to end of a string
	size_t capacity; // total number of characters can be hold
	size_t length;   // total length of a string
} string;

/******************************************************
 *               HELPER FUNCTIONS
 ******************************************************/
static int _strlen(const char * const str)
{
    const char *p = str;
    const char *q = str;
	while(*q)
    {
        ++q;
    }

	return q - p;
}

/******************************************************
 *                 Member Functions
 ******************************************************/
string* _new(const char * const str)
{
	// initialize member variables in struct String
	string *work = malloc(sizeof(*work));
	work->str = malloc(INITIAL_BUFFER * sizeof(char));
	work->beg = work->end = NULL;
	work->capacity = INITIAL_BUFFER;
	work->length = _strlen(str);

	// @TODO: check if length > capacity, if so realloc

	// copy string
	int length = work->length;
	for(int i=0; i<length; ++i)
	{
		(work->str)[i] = str[i];
	}
	(work->str)[length] = '\0';

	work->beg = &(work->str)[0];
	work->end = &((work->str)[length]); // should be NULL('\0')

	return work;
}

void* _free(string *a)
{
	if(a == NULL)
	{
		return NULL;
	}

	a->beg = a->end = NULL;
	free(a->str);
	a->str = NULL;
	free(a);
	a = NULL;

	return a;
}

/******************************************************
 *                   Capacity
 ******************************************************/
int _size(const string *s)
{
	return s->end - s->beg;
}

int _length(const string *s)
{
	return s->end - s->beg;
}

// resize string
static void* _resize1(string *s, size_t n)
{
	// @TODO: check n > capacity

	s->str[n] = '\0';
	s->length = n;
	s->end = &(s->str)[n];

	return s;
}

// resize string and fill in with 'ch'
static void* _resize2(string *s, size_t n, const char *ch)
{

	// @TODO: check n > capacity

	if(s->length < n)
	{
		for(int i=s->length; i<n; ++i)
		{
			s->str[i] = *ch;
		}
	}

	_resize1(s, n);
}

void* _resize(string *s, size_t n, ...)
{
	va_list v;
	va_start(v, n);

	const char *c = va_arg(v, const char *);
	if(*c == '\0')
	{
		_resize1(s, n);
	}
	else
	{
		_resize2(s, n, c);
	}
	va_end(v);

	return s;
}

int _capacity(const string *s)
{
	return s->capacity;
}

void* _reserve(string *s, size_t n)
{
	if(s == NULL)
	{
		return NULL;
	}

	if(n > s->capacity)
	{
		s->capacity = n;
		s->str = realloc(s->str, n);
	}

	return s;
}

void* _clear(string *s)
{
	if(s == NULL)
	{
		return NULL;
	}

	(s->str)[0] = '\0';
	s->length = 0;
	s->beg = s->end = NULL;

	return s;
}
_Bool isEmpty(const string *s)
{
	return (s->length) == 0;
}

void* _shrink_to_fit(string *s)
{
	if(s == NULL)
	{
		return NULL;
	}

	size_t length = s->length;
	s->str = realloc(s->str, length);
	s->capacity = length;
	return s;
}

/******************************************************
 *                   Element Acces
 ******************************************************/
char _at(const string *s, size_t index)
{
	// @TODO: null check and abort

	return (s->str)[index];
}

char _back(const string *s)
{
	// @TODO: null check and abort

	return (s->str)[s->length-1];
}

char _front(const string *s)
{
	// @TODO: null check and abort

	return *(s->str);
}
/******************************************************
 *                     Modifiers
 ******************************************************/
void* _push_back(string *s, char ch)
{
	if(s == NULL)
	{
		return NULL;
	}

	size_t length = s->length;
	if(length == s->capacity)
	{
		s->str = realloc(s->str, length << 1);
		s->capacity = length << 1;
	}

	s->str[length] = ch;
	(s->length)++;
	s->str[length+1] = '\0';

	return s;
}

string* _assign(string *s, const char * const str)
{
	// initialize member variables in struct String
	if(s == NULL)
	{
		s = malloc(sizeof(*s));
		s->str = malloc(INITIAL_BUFFER * sizeof(char));
		s->beg = s->end = NULL;
		s->capacity = INITIAL_BUFFER;
		s->length = _strlen(str);
	}

	// @TODO:  check if capacity < strlen(str)

	size_t length = _strlen(str);
	s->length = length;

	for(int i=0; i<length; ++i)
	{
		(s->str)[i] = str[i];
	}

	(s->str)[length] = '\0';

	s->beg = &((s->str)[0]);
	s->end = &((s->str)[length]);

	return s;
}

/******************************************************
 *                 String Operations
 ******************************************************/
const char* c_str(const string *s)
{
	return s->str;
}
