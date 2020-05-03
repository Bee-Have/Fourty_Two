#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		ft_countstr(char const *s1, char const *set, int len)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		if (set[j] != '\0')
		{
			if (s1[i] == set[j])
			{
				len++;
				i++;
				j = 0;
			}
			else if (set[j] != '\0')
				j++;
			else
				i++;
		}
		else
			i++;
	}
	i--;
	j = 0;
	while (i > 0)
	{
		if (s1[i] == set[j])
		{
			len++;
			i--;
			j = 0;
		}
		else if (set[j] != '\0')
			j++;
		else
			return (len);
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	char	cp[] = "tralala";

	len = 0;	
	len = ft_countstr(s1, set, len);
	printf("%d\n", len);
	return (&cp);
}

int		main(void)
{
	char	str[] = "AABBBJJJA";
	char	set[] = "AB";

	printf("%s\n", ft_strtrim(str, set));
	return (0);
}
