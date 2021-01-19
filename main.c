#include "ft_printf.h"

int		main()
{
	int		res = 0;
	int		myres = 0;

	myres = ft_printf("me%.*c\n", 3, 'a');
	res = printf("ye%.3c\n", 'a');
	printf("16[%d]-[%d]\n", myres, res);
	return (0);
}
