#include<unistd.h>
#include<stdio.h>
#include<string.h>

int     ft_strlcpy(char *dst, char *src, int size)
{
    int i;

    i = 0;
    if (size < 0)
        return (0);
    while (src[i] != '\0' && size > 0)
    {
        dst[i] = src[i];
        i++;
        size--;
    }
    dst[i] = '\0';
    return (i);
}

int     main(void)
{
    char dst[6] = {"Hello "};
    char src[5] = {"World"};

    char dstalt[6] = {"Hello "};
    char srcalt[5] = {"World"};

    printf("%s%s , %s%s", dst, src, dstalt, srcalt);
    ft_strlcpy(dst, src, 6);
    strlcpy(dstalt, srcalt, 5);
    printf("%s%s , %s%s", dst, src, dstalt, srcalt);
}
