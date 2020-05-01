#include<unistd.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int 	main(void)
{
	int i = 0;
	char test[] = "8734hf29qw50aa4782d7`18977532";

	printf("%s\n", test);
	while (test[i] != '\0')
	{
		printf("%d", ft_isdigit(test[i]));
		i++;
	}
	printf("\n");
	i = 0;
	while (test[i] != '\0')
	{
		printf("%d", isdigit(test[i]));
		i++;
	}
}
