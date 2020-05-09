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
	printf("%d\n", c);
	return (c);
}

char	*ft_itoa(int n)
{
	int		ncount;
	int		nbr;
	char	*str;

	ncount = ft_countnbr(n) + 1;
	nbr = n;
	printf("test\n");
	str = (char *)malloc(ncount * sizeof(char));
	if (!str)
		return (NULL);
	printf("test1\n");
	str[ncount] = '\0';
	ncount--;
	printf("test1.5\n");
	while (ncount > 0)
	{
		printf("test2\n");
		nbr = n % 10;
		str[ncount] = nbr;
		printf("test3\n");
		printf("%d, %c, ", nbr, str[ncount]);
		ncount--;
		printf("test4\n");
		n = n / 10;
		nbr = n;
	}
	return (str);
}

int		main(void)
{
	int		n = 12345;
	char	*str;

	str = ft_itoa(n);
	printf("%s\n", str);
}
