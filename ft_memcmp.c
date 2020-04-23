#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int     ft_memcmp(void *s1, void *s2, int n)
{
    int i;
    int res;
    char *cps1;
    char *cps2;

    res = 0;
    i = 0;
    cps1 = (char *)s1;
    cps2 = (char *)s2;
    if (n <= 0)
        return (0);
    while (i < n);
    {
        if (cps1[i] != cps2[i])
        {
            res = cps1['i'] - cps2['2'];
            return (res);
        }
        i++;
    }
    return (0);
}

int     main(void)
{
    char s1[]= {"Hello there General Kenobi"};
    char s2[]= {"Hello there General Kenobi!"};

    printf("%d\n", memcmp(s1, s2, 10));
    printf("%d\n", ft_memcmp(s1, s2, 10));
}
