#include <unistd.h>

int     ft_isalnum(char *str)
{
    int i;

    i = 0;
    if (!str)
        return (0);
    while (str[i] != '\0')
    {
        if (str[i] < '0' || str[i] > 'z')
            return (0);
        else if (str[i] > '9' && str[i] < 'A')
            return (0);
        else if (str[i] > 'Z' && str[i] < 'a')
            return (0);
        i++;
    }
    return (1);
}

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int     main(int argc, char **argv)
{
    printf("mine = %d\n", ft_isalnum(argv[argc]));
    printf("perf = %d\n", isalnum(argv[argc]));
}
