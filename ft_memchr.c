#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void    *ft_memchr(void *s, int c, int n)
{
    int i;
    char *cps;

    i = 0;
    cps = (char *)s;
    while (i < n)
    {
        if (cps[i] == (char)c)
            return (&cps[i]);
        i++;
    }
    return (NULL);
}

int    main(void)
{
    char origin[] = {"Hello there general Kenobi"};

    printf("%s\n", (char *)memchr(origin, 'g', 20));
    printf("%s\n", (char *)ft_memchr(origin, 'g', 20));
    return (0);
}
