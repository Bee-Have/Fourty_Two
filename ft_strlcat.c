#include <unistd.h>
#include <stdio.h>
#include <string.h>

int		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (dst[i] != '\0' && i < dstsize)
		i++;
	while (src[j] != '\0' && i < (dstsize - 1))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (i);
}
