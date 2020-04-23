#include<unistd.h>
#include<stdio.h>
#include<string.h>

void *ft_memcpy(void *dest, void *src, int n)
{
    int i;
    char *strdest;
    char *strsrc;

    strdest = (char *)dest;
    strsrc = (char *)src;
    i = 0;
    while (i < n)
    {
        strdest[i] = strsrc[i];
        i++;
    }
    return (dest);
}

int     main(void)
{
    char from1[14] = {"this is a test"};
    char from2[17] = {"this is also test"};
    char to[17];

    printf("%s\n", to);

    ft_memcpy(to, from1, 10);
    printf("%s\n", to);

    memcpy(to, from2, 10);
    printf("%s\n", to);
}
