#include <unistd.h>
#include <stdio.h>
#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	int		i;
	char	*tab;

	tab = (char *)b;
	i = 0;
	while (i < len)
	{
		tab[i] = (char)c;
		i++;
	}
	return (b);
}
