#include<unistd.h>
#include<stdio.h>
#include<string.h>

int		ft_strlcat(char *dst, char *src, int size)
{
	int i;

	i = 0;
	while (dst[i] != '\0' && i < size)
		i++;
	while (src[i] != '\0' && i < size)
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return (i);
}

int		main(void)
{
    char dst[] = {"Hello"};
    char src[] = {"World"};

    char dstalt[] = {"Hello"};
    char srcalt[] = {"World"};

    printf("%s %s\n%s %s\n\n", dst, src, dstalt, srcalt);
    printf("%d\n", ft_strlcat(dst, src, 10));
    printf("%lu\n", strlcqt(dstalt, srcalt, 10));
    printf("%s %s\n%s %s\n\n", dst, src, dstalt, srcalt);
}
