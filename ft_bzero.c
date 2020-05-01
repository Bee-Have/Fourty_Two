#include <stdio.h>
#include <unistd.h>
#include <string.h>

void	ft_bzero(void *s, int n)
{
	int		i;
	char	*tab;

	tab = (char *)s;
	i = 0;
	while (i <= n)
	{
		tab[i] = (char)'\0';
		i++;
	}
}
