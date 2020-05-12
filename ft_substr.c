#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*cp;

	i = 0;
	cp = (char *)malloc(len);
	if (!cp)
		return (NULL);
	while (s[start] != '\0')
	{
		cp[i] = s[start];
		i++;
		start++;
	}
	cp[i++] = '\0';
	return (cp);
}
