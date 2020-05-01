#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_itoa(int nb, char *str, int base)
{
	char	*bs[36];
	int		nbr;
	int		i;

	bs = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	i = -1;
	nbr = nb;
	while (nbr > 0)
	{
		i++;
		nbr /= base;
	}
	while (nb > 0)
	{
		nbr = nb % base;
		str[i] = bs[nbr];
		i--;
		nb = nb / base;
	}
	return (str);
}
