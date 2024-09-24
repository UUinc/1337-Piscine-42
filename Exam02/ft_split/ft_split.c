#include <stdlib.h>

int count_len(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        i++;
    }
    return (i);
}

int is_whitespace(char c)
{
    if (c == ' ' || c == '\t' || c == '\n')
        return (1);
    return (0);
}

int count_words(char *str)
{
    int i;
    int f;
    int count;

    i = 0;
    f = 1;
    count = 0;
    while (str[i])
    {
        if (is_whitespace(str[i]) && f == 0)
            f = 1;
        else if (!is_whitespace(str[i]) && f)
        {
            f = 0;
            count++;
        }
        i++;
    }
    return (count);
}

char *get_word(char *str, int *index)
{
    int i;
    int start;
    int end;
    int len;
    int f;
    char *word;

    f = 1;
    start = 0;
    end = 0;
    while (str[*index])
    {
        if (!is_whitespace(str[*index]) && f)
        {
            start = *index;
            f = 0;
        }
        if (is_whitespace(str[*index]) && f == 0)
        {
            end = *index - 1;
            break ;
        }
        (*index)++;
    }
    if (*index == 0)
        return NULL;
    if (end == 0)
        end = *index - 1;
    len = end - start + 1;
    word = (char *) malloc(sizeof(char) * (len + 1));
    i = 0;
    while (i < len)
    {
        word[i] = str[start + i];
        i++;
    }
    word[i] = '\0';
    return (word);
}

char    **ft_split(char *str)
{
    int i;
    int pos;
    int size;
    char **arr;

    size = count_words(str);
    arr = (char **) malloc(sizeof(char *) * (size + 1));
    if (arr == NULL)
        return (NULL);
    i = 0;
    pos = 0;
    while (i < size)
    {
        arr[i] = get_word(str, &pos);
        i++;
    }
    arr[size] = 0;
    return (arr);
}
