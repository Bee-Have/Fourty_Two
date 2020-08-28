#include <unistd.h>
#include <stdio.h>
#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char	*string;

	i = 0;
	j = 0;
	string = (char *)haystack;
	if (!needle)
		return (string);
	while (string[i] != '\0' && i < len)
	{
		while (string[i] == needle[j])
		{
			i++;
			j++;
		}
		if (needle[j] == '\0')
			return (&string[i - j]);
		else
			i++;
	}
	return (NULL);
}
