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
        if (str[i] == ' ' && f == 0)
            f = 1;
        else if (str[i] != ' ' && f)
        {
            f = 0;
            count++;
        }
        i++;
    }
    return (count);
}
