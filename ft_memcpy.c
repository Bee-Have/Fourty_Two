#include <unistd.h>
#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int		i;
	char	*strdest;
	char	*strsrc;

	strdest = (char *)dst;
	strsrc = (char *)src;
	i = 0;
	while (i < n)
	{
		strdest[i] = strsrc[i];
		i++;
	}
	return (dst);
}
