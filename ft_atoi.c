#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void ft_putchar(char a)
{
    write(1, &a, 1);
}

void ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        ft_putchar(str[i]);
        i++;
    }

}

int ft_strlen(char *str)
{
    int i;
    int len;

    i = 0;
    len = 0;
    if (str)
    {
        while (str[i] != '\0')
            i++;
        return(len);
    }
    return(0);
}

int ft_atoi(char *str)
{
    int i;
    long int res;

    i = 0;
    res = 0;
    if (!str)
        return (0);
    if (str[i] == '-')
        i++;
    if (res >= 2147483647)
    {
        if (str[0] != '-' && res == 2147483647)
            return (res);
        else if (str[0] == '-' && res == 2147483648)
            return (-2147483648);
        if (res >= 2147483648)
        {
            ft_putstr("string value is greater then int maximum value\n");
            return (0);
        }
    }
    if (str[0] == '-')
        res *= -1;
    return (res);
}

int main(int argc, char **argv)
{
    if (argc && argc != 0)
    {
        printf("perf= %d\n", atoi(argv[1]));
        printf("mine= %d\n", ft_atoi(argv[1]));
    }
    return (0);
}
