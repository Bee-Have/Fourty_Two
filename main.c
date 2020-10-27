#include <stdio.h>

int		main()
{
	unsigned int	str = 11;

	printf("%.*u\n", 5, str);
	printf("%.*u\n", -5, str);
	printf("%.*u\n", 0, str);
	return (0);
}
