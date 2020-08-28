#include <unistd.h>
#include <stdio.h>
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	int	i;
	char	*string;

	i = 0;
	string = (char *)s;
	while (string[i] != '\0')
	{
		if (string[i] == c)
			return (&string[i]);
		i++;
	}
	return (NULL);
}
