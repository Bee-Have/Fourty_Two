#include "ft_printf.h"

int		main()
{
	int		ret = 0;
	int		ret2 = 0;
	int		nb = 4294967295;

	ret = ft_printf("%03d\n",		nb);
	ret2 = printf("%03d\n",		nb);
	printf("14[%d]=[%d]\n", ret, ret2);
	ret = ft_printf("%010d\n",		nb);
	ret2 = printf("%010d\n",		nb);
	printf("15[%d]=[%d]\n", ret, ret2);
	return (0);
}