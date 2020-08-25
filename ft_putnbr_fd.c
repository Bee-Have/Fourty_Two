#include<unistd.h>
#include<stdio.h>
#include<string.h>

void	ft_putnbr_fd(int n, int fd)
{
	int	nbr;
	char 	value;

	nbr = 0;
	value = nbr;
	if (n >= 10)
	{
		nbr = n % 10;
		n = n / 10;
		value = nbr + '0';
		ft_putnbr_fd(n, fd);
		write(fd, &value, 1);
	}
	else if (n < 10)
	{
		value = (n % 10) + '0';
		write (fd, &value, 1);
	}
}
