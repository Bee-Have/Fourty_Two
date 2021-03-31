#include "ft_printf.h"

int		main()
{
	int		ret = 0;
	int		ret2 = 0;
	char	c = 0;

	ret = ft_printf("%-5c\n", 		c);
	ret2 = printf("%-5c\n", 		c);
	printf("5[%d]=[%d]\n", ret, ret2);
	return (0);
}