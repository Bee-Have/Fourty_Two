#include "ft_printf.h"

int		main()
{
	int		ret;
	int		ret2;

	ret = 0;
	ret2 = 0;

	ret = ft_printf("7 Oi%0*d", 0, -2147483647);
	printf("\n");
	ret2 = printf("7 Oi%0*d", 0, -2147483647);
	printf("\n");
	printf("[%d]=[%d]\n", ret, ret2);
	return (0);
}