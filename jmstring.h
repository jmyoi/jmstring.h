#pragma once

#include <stdlib.h>

#define INITIAL_BUFFER 16

typedef struct String
{
	// public
	char *str;

	// this should be private (@TODO: find a way to hide this?)
	const char * beg;    // points to beginning of a string
	const char * end;    // points to end of a string
	int capacity; // total number of characters can be hold
	int length;   // total length of a string
} string;

/******************************************************
 *               HELPER FUNCTIONS
 ******************************************************/
static int _strlen(const char *str)
{
	int index = 0;
	while(str[index] != '\0')
	{
		++index;
	}

	return index;
}

/******************************************************
 *                 Member Functions
 ******************************************************/
static string* newstr(const char * const str)
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

/******************************************************
 *                   Capacity
 ******************************************************/
int size(const string *s)
{
	return s->end - s->beg;
}

int length(const string *s)
{
	return s->end - s->beg;
}

int capacity(const string *s)
{
	return s->capacity;
}
/******************************************************
 *                   Element Acces
 ******************************************************/

/******************************************************
 *                     Modifiers
 ******************************************************/
string* assign(string *work, const char * const str)
{
	// @TODO: work == NULL

	// @TODO:  check if capacity < strlen(str)

	size_t length = _strlen(str);

	for(int i=0; i<length; ++i)
	{
		(work->str)[i] = str[i];
	}

	(work->str)[length] = '\0';

	work->beg = &(work->str)[0];
	work->end = &(work->str)[length];

	return NULL;
}

/******************************************************
 *                 String Operations
 ******************************************************/
const char* c_str(const string *s)
{
	return s->str;
}
