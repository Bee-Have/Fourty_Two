#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	int		i;
	char	*cpdest;
	char	*cpsrc;

	i = 0;
	cpdest = (char *)dst;
	cpsrc = (char *)src;
	while (i <= n)
	{
		cpdest[i] = cpsrc[i];
		if (cpsrc[i] == (char)c)
			return (dst);
		i++;
	}
	return (dst);
}
