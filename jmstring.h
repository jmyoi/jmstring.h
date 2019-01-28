#pragma once

#include <stdlib.h>

#define INITIAL_BUFFER 32

typedef struct String
{
	// public
	char *str;
	int length;   // total length of a string

	// this should be private (@TODO: find a way to hide this?)
	const char * beg;    // points to beginning of a string
	const char * end;    // points to end of a string
	int capacity; // total number of characters can be hold
} string;

int _strlen(const char *str)
{
	int index = 0;
	while(str[index] != '\0')
	{
		++index;
	}

	return index;
}

string* newstr(const char * const str)
{
	// initialize member variables in struct String
	string *work = malloc(sizeof(*work));
	work->str = malloc(INITIAL_BUFFER * sizeof(char));
	work->beg = work->end = NULL;
	work->capacity = 32;
	work->length = _strlen(str);

	// @TODO: check if length > capacity, if so realloc

	// copy string
	int length = work->length;
	for(int i=0; i<length; ++i)
	{
		(work->str)[i] = str[i];
	}

	work->beg = work->str;
	work->end = &((work->str)[length]); // should be NULL('\0')

	return work;
}

const char* c_str(const string *s)
{
	return s->str;
}

int size(const string *s)
{
	return s->end - s->beg;
}

int length(const string *s)
{
	return s->end - s->beg;
}

