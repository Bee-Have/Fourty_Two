#include<unistd.h>
#include<stdio.h>
#include<string.h>

int		ft_strlcat(char *dst, char *src, int size)
{
	int i;

	i = 0;
	while (dst[i] != '\0' && i < size)
		i++;
	while ()
}

int		main(void)
{
	char src[] = "Hello";
	char dst[] = "World";

	printf("%s %s\n", dst, src);
	printf("%lu\n", strlcat(dst, src, 10));
	printf("%s %s\n", dst, src);
}

