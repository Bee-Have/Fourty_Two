#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void *ft_memmove(void *dest, void *src, int n)
{
    int i;
    char tempdest[n];
    char *cpdest;
    char *cpsrc;

    i = 0;
    cpdest = (char *)dest;
    cpsrc = (char *)src;
    while (i < n)
    {
        tempdest[i] = cpsrc[i];
        i++;
    }
    i = 0;
    while (i < n)
    {
        cpdest[i] = tempdest[i];
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

    ft_memmove(to, from1, 14);
    printf("%s\n", to);

    memmove(to, from2, 17);
    printf("%s\n", to);
}
