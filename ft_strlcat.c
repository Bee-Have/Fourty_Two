#include<unistd.h>
#include<stdio.h>
#include<string.h>

int     main(void)
{
    char dst[6] = {"Hello "};
    char src[5] = {"World"};

    char dstalt[6] = {"Hello "};
    char srcalt[5] = {"World"};

    printf("%s%s , %s%s\n", dst, src, dstalt, srcalt);
    ft_strlcpy(dst, src, 6);
    strlcpy(dstalt, srcalt, 5);
    printf("%s%s , %s%s\n", dst, src, dstalt, srcalt);
}
