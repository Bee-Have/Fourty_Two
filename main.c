#include "ft_printf.h"

int		main()
{
	int		res;
	int		myres;
	//void	*test;
	//char	c = 'A';
	//char	*str = "hello";
	//int		nbr = 11;

	//printf("%1.s", str);
	myres = ft_printf("mee=%.*X HAHA\n", 5, 99);
	res = printf("dis=%.*X HAHA\n", 5, 99);

	printf("me[%d]-[%d]dis\n", myres, res);
	return (0);
}
