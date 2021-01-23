#include "ft_printf.h"

int		main()
{
	int		res = 0;
	int		myres = 0;

	myres = ft_printf("me%.*0c\n", 3, 'a');
	res = printf("ye%.*0c\n", 3, 'a');
	printf("23[%d]-[%d]\n", myres, res);
	return (0);
}
