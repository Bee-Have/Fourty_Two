#include<unistd.h>
#include<stdio.h>
#include<string.h>

int		ft_strlcat(char *dst, char *src, int size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dst[i] != '\0' && i < size)
		i++;
	while (src[j] != '\0' && i < (size - 1))
    {
        dst[i] = src[j];
        i++;
		j++;
    }
    dst[i] = '\0';
    return (i);
}

int		main(void)
{
    char dst[11] = {"Hello"};
    char src[] = {"World"};

    char dstalt[11] = {"Hello"};
    char srcalt[] = {"World"};

    printf("%s %s\n%s %s\n\n", dst, src, dstalt, srcalt);
    printf("%d\n", ft_strlcat(dst, src, 11));
    printf("%lu\n", strlcat(dstalt, srcalt, 11));
    printf("%s %s\n%s %s\n\n", dst, src, dstalt, srcalt);
}
