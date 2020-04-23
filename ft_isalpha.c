#include <unistd.h>

int	ft_isalpha(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] < 'A' || str[i] > 'z')
			return (0);
		else if (str[i] > 'Z' && str[i] < 'a')
			return (0);
		i++;
	}
}
