void _append (string_t_cpc s, char *src)
{
}

void _push_back (string_t_pc s, char *ch)
{
}

/* idk if this will work but we'll see */
#if 1
void _assign (string_t_pc s, ...)
{
}

void _assign1 (string_t_pc s, char *src)
{
}

void _assign3 (string_t_pc s, int n, char *ch)
{
}

void _assign2 (string_t_pc s, char *src, int start, int end)
{
}
#endif

void _insert (string_t_pc s, size_t pos, char *src)
{
}

/* erase 'n' characters from 'pos' index */
void _erase (string_t_pc s, size_t pos, size_t n)
{
}

/* replace 'n' chars from 'pos' index with 'src' */
void _replace (string_t_pc s, size_t pos, size_t n, char *src)
{
}

/* swapping two address should work.... r..ight? */
void _swap (string_t **s1, string_t **s2)
{
    string_t *temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

void* _pop_back (string_t_pc s)
{
    if (s == NULL || s->length == 0)
    {
        return NULL;
    }
    
    --(s->length);
    (s->str)[s->length] = '\0';
    s->end = --(s->end);

    return s->str;
}
