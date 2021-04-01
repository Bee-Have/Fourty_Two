#include "ft_printf.h"

int		main()
{
	int		ret = 0;
	int		ret2 = 0;
	char	*var = "abc";

	ret = ft_printf("%.3d\n", 0);
	ret2 = printf("%.3d\n", 0);
	printf("64[%d]=[%d]\n", ret, ret2);
	return (0);
}