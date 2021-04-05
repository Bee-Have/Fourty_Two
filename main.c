#include "ft_printf.h"

int		main()
{
	int		ret = 0;
	int		ret2 = 0;
	long int		nb = 2147483647;
	long int		nb1 = -21474836;

	ret2 = printf("%5\n");
	ret = ft_printf("%5\n");
	printf("57[%d]=[%d]\n", ret, ret2);
	return (0);
}