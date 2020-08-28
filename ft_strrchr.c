#include <stdio.h>
#include <unistd.h>
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	occurrence;
	char	*string;

	i = 0;
	occurrence = 0;
	string = (char *)s;
	while (string[i] != '\0')
	{
		if (string[i] == c)
			occurrence = i;
		i++;
	}
	if (occurrence == 0 && string[occurrence] != c)
		return (NULL);
	return (&string[occurrence]);
}
