#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	*ft_memmove(void *dst, void *src, int len)
{
	int		i;
	char	tempdst[len];
	char	*cpdst;
	char	*cpsrc;

	i = 0;
	cpdst = (char *)dst;
	cpsrc = (char *)src;
	while (i < len)
	{
		tempdst[i] = cpsrc[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		cpdst[i] = tempdst[i];
		i++;
	}
	return (dst);
}
