#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int		ft_countnbr(int n)
{
	int		c;

	c = 0;
	while(n > 0)
	{
		n = n / 10;
		c++;
	}
	return (c);
}

char	*ft_itoa(int n)
{
	int		ncount;
	int		nbr;
	char	*str;

	ncount = ft_countnbr(n) + 1;
	nbr = n;
	str = (char *)malloc(ncount * sizeof(char));
	if (!str)
		return (NULL);
	str[ncount] = '\0';
	ncount--;
	while (ncount > 0)
	{
		nbr = n % 10;
		str[ncount] = nbr;
		ncount--;
		n = n / 10;
		nbr = n;
	}
	return (str);
}
