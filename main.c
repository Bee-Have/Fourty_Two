#include <stdio.h>

int		main()
{
	unsigned int		i = 429496;
	//int		j = 987654321;
	char	c = 'a';
	//char	d = 'b';
	char	*str = "hello world";
	//char	*str2 = "no thanks";

	//printf("%05X\n", i);
	printf("%00i\n", i);
	printf("%c\n", c);
	printf("%s\n", str);
	printf("%%");

	return (0);
}