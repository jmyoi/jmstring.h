#pragma once

char _at (string_t_cpc s, const size_t pos)
{
    if (pos < 0 || pos >= s->length)
    {
        return '\0';
    }

    return (s->str)[pos];
}

char* _back (string_t_cpc s)
{
    if (s == NULL)
    {
        return NULL;
    }

    return s->end;
}

char* _front (string_t_cpc s)
{
    if (s == NULL)
    {
        return NULL;
    }

    return s->beg;
}
