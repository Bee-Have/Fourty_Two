#include<unistd.h>
#include<stdio.h>
#include<string.h>

char *ft_strchr(char *s, int c)
{
    int i;

    i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == c)
            return (&s[i]);
        i++;
    }
    return (NULL);
}

int     main(void)
{
    char *str = {"Hello There General Kenobi"};

    printf("%s\n", ft_strchr(str, 'T'));
    printf("%s\n", strchr(str, 'T'));
}
