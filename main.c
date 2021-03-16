#include "ft_printf.h"

int		main()
{
	int		ret = 0;
	int		ret2 = 0;
	char	var = "abc";
	unsigned int		nb = 4294967295 + 589;

	ret = ft_printf("%%p::[%010.1d]\n", -8473);
	ret2 = printf("%%p::[%010.1d]\n", -8473);
	printf("68[%d]=[%d]\n", ret, ret2);
	return (0);
}