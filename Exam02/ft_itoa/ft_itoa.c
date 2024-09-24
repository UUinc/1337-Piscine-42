#include <stdlib.h>

int ft_nbrlen(long nbr)
{
    int len;

    if (nbr == 0)
        return (1);
    len = 0;
    if (nbr < 0)
    {
        len++;
        nbr = -nbr;
    }
    while(nbr > 0)
    {
        nbr /= 10;
        len++;
    }
    return (len);
}

int ft_pow(int nbr, int pow)
{
    int i;
    int p;

    i = 0;
    p = 1;
    while (i < pow)
    {
        p *= nbr;
        i++;
    }
    return (p);
}

void    ft_cpystr(char *dest, char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        *(dest++) = str[i++];
    }
}

char    *ft_itoa(int nbr)
{
    int i;
    int p;
    int len;
    char    *str;

    len = ft_nbrlen((long)nbr);
    str = (char *) malloc(sizeof(char) * (len + 1));
    if (str == NULL)
        return (NULL);
    i = 0;
    if (nbr == -2147483648)
    {
        ft_cpystr(str, "-2147483648");
        str[11] = '\0';
        return  (str);
    }
    if (nbr < 0)
    {
        str[i] = '-';
        nbr = -nbr;
        i++;
    }
    while (i < len) //12
    {
        p = ft_pow(10, len - i - 1);
        str[i] = nbr / p + '0';
        nbr = nbr - (str[i] - '0') * p;
        i++;
    }
    str[i] = '\0';
    return (str);
}
