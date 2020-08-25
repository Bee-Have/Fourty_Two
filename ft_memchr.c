#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	int		i;
	char	*cps;

	i = 0;
	cps = (char *)s;
	while (i < n)
	{
		if (cps[i] == (char)c)
			return (&cps[i]);
		i++;
	}
	return (NULL);
}
