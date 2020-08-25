#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char	*str;

	i = 0;
	while (s[i] != '\0')
		i++;
	str = (char *)malloc(i++ * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	return(str);
}
