#include "ft_printf.h"

int		main()
{
	int		res = 0;
	int		myres = 0;
	int		test = 5;

	myres = ft_printf("me%-5%\n");
	res = printf("ye%-5%\n");
	printf("3[%d]-[%d]\n", myres, res);
	return (0);
}