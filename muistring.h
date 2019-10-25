#pragma once

#include <stdlib.h>

#define MIN_CAPACITY (10)
#define MAX_CAPACITY (0xFFFFFFFF)

typedef struct string
{
    /* public variable */
    char *str;

    /* private variable (not really) */
    char *beg;    /* points to beginning of the string */
    char *end;    /* points to end of the string */
    size_t capacity;    /* size of allocated storage */
    size_t length;      /* current length of a string */
} string_t;

typedef string_t String;

typedef string_t const * const string_t_cpc;
typedef string_t const *       string_t_cp;
typedef string_t * const       string_t_pc;

/*****************************************************
 *                 HELPER FUNCTIONS                  *
 *****************************************************/
size_t _strlen(const char * const ch)
{
    const char *p = ch;
    const char *q = ch;

    while(*(q++));

    return q - p - 1;
}

void _strcpy(char * const src, char *dest)
{
    char *temp = src;

    while(*temp != '\0')
    {
        *dest = *temp;
        ++temp;
        ++dest;
    }

    *dest = *temp;
}

/*****************************************************
 *                     CONSTRUCTORS                  *
 *****************************************************/
String* _new(char *str)
{
    String *newstr = malloc(sizeof(*newstr));
    size_t size;

    newstr->capacity = MIN_CAPACITY;
    if (str == NULL)
    {
        newstr->str = NULL;
        newstr->beg = newstr->end = NULL;
        newstr->length = 0;
    }
    else
    {
        size = _strlen(str);
        newstr->str = malloc(sizeof(char) * size);
        newstr->length = size;

        _strcpy(str, newstr->str);
        newstr->beg = str;
        newstr->end = str + size - 1;

        if (size >= MIN_CAPACITY)
        {
            newstr->capacity = MIN_CAPACITY << 1;
        }
    }

    return newstr;
}

void* delete(string_t *s)
{
    if (s == NULL)
    {
        return NULL;
    }

    s->beg = s->end = NULL;
    free(s->str);
    s->str = NULL;

    free(s);
    s = NULL;

    return s;
}

/*****************************************************
 *                SETTERS & GETTERS                  *
 *****************************************************/

/*
 * @TODO
 * GETTER removed => _data() is equivalent to it
 * SETTER will be replaced with => _assign() in lib/modifiers.h
 * */
void _setstr(string_t_pc s, char *word)
{
    size_t size;

    _strcpy(word, s->str);

    size = _strlen(s->str);
    s->length = size;
    s->beg = s->str;
    s->end = s->str + size - 1;
}

/*****************************************************
 *                  FUNCTIONALITIES                  *
 *****************************************************/
#include "./lib/capacity.h"
#include "./lib/element_access.h"
#include "./lib/modifiers.h"
#include "./lib/strops.h"
