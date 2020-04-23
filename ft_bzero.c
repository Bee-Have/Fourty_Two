#include<stdio.h>
#include<unistd.h>
#include<string.h>

void    ft_bzero(void *s, int n)
{
    int i;
    char *tab;

    tab = (char *)s;
    i = 0;
    while (i <= n)
    {
        tab[i] = (char)'\0';
        i++;
    }
}

int     main(void)
{
    char test1[] = {"this is a test"};
    char test2[] = {"this is also a test"};

    printf("%s\n", test1);
    printf("%s\n", test2);

    ft_bzero(test1, 2);
    bzero(test2, 2);

    printf("%s\n", test1);
    printf("%s\n", test2);
}
