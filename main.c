#include "ft_printf.h"

int		main()
{
	int		ret = 0;
	int		ret2 = 0;
	int		nb = -2;

	ret = ft_printf("%BLABLABLABLA\n");
	ret2 = printf("%BLABLABLABLA\n");
	printf("57[%d]=[%d]\n", ret, ret2);
	return (0);
}