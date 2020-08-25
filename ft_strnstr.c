#include <unistd.h>
#include <stdio.h>
#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!needle)
		return (haystack);
	while (haystack[i] != '\0' && i < len)
	{
		while (haystack[i] == needle[j])
		{
			i++;
			j++;
		}
		if (needle[j] == '\0')
			return (&haystack[i - j]);
		else
			i++;
	}
	return (NULL);
}
