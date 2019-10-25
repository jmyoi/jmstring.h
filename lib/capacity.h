#pragma once
/* capacity.h */

#include <stdlib.h>
#include <stdarg.h>

/* for this program => 1 char = 1 byte */
size_t _size(string_t_cpc s)
{
    return s->length;
}

/* synonymous to _size */
size_t _length(string_t_cpc s)
{
    return s->length;
}

/* unsigned 32 bits */
unsigned _maxsize(void)
{
    return MAX_CAPACITY;
}

size_t _capacity(string_t_cpc s)
{
    return s->capacity;
}

_Bool _empty(string_t_cpc s)
{
    return s->length == 0;
}

void* _clear(string_t_pc s)
{
    if (s == NULL)
    {
        return NULL;
    }

    (s->str)[0] = '\0';
    s->length = 0;
    s->beg = s->end = NULL;

    return s;
}

void* _reserve(string_t_pc s, const size_t n)
{
    if (n == 0 || n < s->capacity || n > MAX_CAPACITY)
    {
        return NULL;
    }

    if (n > s->capacity)
    {
        s->capacity = n;
        s->str = realloc(s->str, n);
    }

    return s;
}

void* _shrink_to_fit(string_t_pc s)
{
    if (s == NULL)
    {
        return NULL;
    }

    s->capacity = s->length;

    return s;
}

static void resize_1(string_t_pc s, const size_t n)
{
    if (n > s->capacity)
    {
        s->capacity = (s->capacity) << 1;
        s->str = realloc(s->str, s->capacity);
    }
    else
    {
        (s->str)[n] = '\0';
        s->length = n;
        s->end = (s->str) + n - 1;
    }
}

static void resize_2(string_t_pc s, const size_t n, const char *ch)
{
    size_t prev_size = _strlen(s->str);
    size_t index;
    resize_1(s, n);

    for (index = prev_size; index < n; ++index)
    {
        (s->str)[index] = *ch;
    }

    s->end = (s->str) + n - 1;
}

void* _resize(string_t_pc s, const size_t n, ...)
{
    va_list v;

    va_start(v, n);
    {
        const char *c = va_arg(v, const char *);
        if (*c == '\0')
        {
            resize_1(s, n);
        }
        else
        {
            resize_2(s, n, c);
        }
    }
    va_end(v);

    return s;
}
