#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		ft_countstr(char const *s1, char const *set, int len, int i)
{
	int		j;
	
	j = 0;
	while (set[j] != '\0')
	{
		if (s1[i] == set[j])
		{
			len++;
			return (ft_countstr(s1, set, len, i++));
		}
		else 
			j++;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		len;
	char	*cp = "tralala";

	i = 0;
	j = 0;
	len = ft_countstr(s1, set, 0, 0);
	printf("%d\n", len);
	return (cp);
}

int		main(void)
{
	char	str[] = "AABBBHHFJJJA";
	char	set[] = "AB";

	ft_strtrim(str, set);
}
