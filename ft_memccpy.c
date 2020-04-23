#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void    *ft_memccpy(void *dest, void *src, int c, int n)
{
    int i;
    char *cpdest;
    char *cpsrc;

    i = 0;
    cpdest = (char *)dest;
    cpsrc = (char *)src;
    while (i <= n)
    {
        cpdest[i] = cpsrc[i];
        if (cpsrc[i] == (char)c)
            return (dest);
        i++;
    }
    return (dest);
}

int     main(void)
{
    char from1[] = {"this is a test"};
    char from2[] = {"this is also a test"};
    char to[] = {"Hello there general Kenobi"};

    printf("%s\n", to);

    ft_memccpy(to, from1, ' ', 14);
    printf("%s\n", to);

    memccpy(to, from2, ' ', 17);
    printf("%s\n", to);
    }
