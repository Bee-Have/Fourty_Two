#include<unistd.h>
#include<stdio.h>
#include<string.h>

void *ft_memset(void *pointer, int value, int count)
{
    int i;
    char *tab;

    tab = (char *)pointer;
    i = 0;
    while (i <= count)
    {
        tab[i] = (char)value;
        i++;
    }
    return (pointer);
}

int main(void)
{
    char pointer[] = {"1234567890"};
    printf("%s\n", pointer);

    ft_memset(pointer, '2', 5);
    printf("%s\n", pointer);

    memset(pointer, 50, 5);
    printf("%s\n", pointer);
}
