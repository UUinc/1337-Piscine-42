#include <unistd.h>

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

int ft_is_possibe(char *str1, char *str2)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (str1[i])
    {
        while (str2[j])
        {
            if (str1[i] == str2[j])
            {
                i++;
                j++;
                break ;
            }
            j++;
        }
        if (str1[i] != '\0' && str2[j] == '\0')
            return (0);
    }
    if (str1[i] == '\0')
        return (1);
    return (0);
}

int main(int ac, char **av)
{
    if (ac != 3)
    {
        write(1, "\n", 1);
        return (1);
    }
    if (ft_is_possibe(av[1], av[2]))
    {
        write(1, av[1], count_len(av[1]));
    }
    write(1, "\n", 1);
}
