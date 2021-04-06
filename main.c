#include "ft_printf.h"

int		main()
{
	int		ret;
	int		ret2;

	ret = 0;
	ret2 = 0;

	ret = ft_printf("%.*s", -3, "hello");
	printf("\n");
	ret2 = printf("%.*s", -3, "hello");
	printf("\n");
	printf("[%d]=[%d]\n", ret, ret2);
	return (0);
}