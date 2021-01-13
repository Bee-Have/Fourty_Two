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
	res = printf("dis=%s HAHA\n", "hello there general Kenobi");
	myres = ft_printf("mee=%s HAHA\n", "hello there general Kenobi");

	printf("me[%d]-[%d]dis\n", myres, res);
	return (0);
}
