#include<unistd.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>

int	ft_isalpha(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int 	main(void)
{
	int i = 0;
	char test[] = "Hello there general Kenobi";

	printf("%s\n", test);
	while (test[i] != '\0')
	{
		printf("%d", ft_isalpha(test[i]));
		i++;
	}
	printf("\n");
	i = 0;
	while (test[i] != '\0')
	{
		printf("%d", isalpha(test[i]));
		i++;
	}
}
