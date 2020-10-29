#include <stdio.h>

int		main()
{
	unsigned int	test;
	int	str = 11;

	test = &str; 
	printf("%p\n", &str);
	printf("%X\n", test);
	printf("%d\n", str);
	return (0);
}
