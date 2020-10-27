#include <stdio.h>

int		main()
{
	char	*str = "Hello World";

	printf("%0*s\n", 5, str);
	printf("%0*s\n", -5, str);
	printf("%0*s\n", 0, str);
	return (0);
}
