#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*cp;

	i = 0;
	if (!s1)
		return (NULL);
	cp = (char *)malloc(sizeof(s1));
	if (!cp)
		return (NULL);
	while (s1[i] != '\0')
	{
		cp[i] = s1[i];
		i++;
	}
	return (cp);
}
