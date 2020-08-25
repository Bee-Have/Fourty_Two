#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int		i;
	int		res;
	char	*cps1;
	char	*cps2;

	res = 0;
	i = 0;
	cps1 = (char *)s1;
	cps2 = (char *)s2;
	if (n <= 0)
		return (0);
	while (i < n && cps1[i] != '\0' && cps2[i] != '\0')
	{
		if (cps1[i] != cps2[i])
		{
			res = cps1[i] - cps2[i];
			return (res);
		}
		i++;
	}
	return (0);
}
