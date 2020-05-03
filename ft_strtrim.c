#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int		ft_findad(const char *s1, const char *set, int bl)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (bl > 0)
	{
		while (s1[j] != '\0')
			j++;
	}
	while (set[i] != '\0')
	{
		if (s1[j] == set[i])
		{
			if (bl == 0)
				j++;
			else
				j--;
			i = 0;	
		}
		else
			i++;
	}
	return (j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		ps;
	int		pe;
	char	*cp;

	i = 0;
	ps = ft_findad(s1, set, 0);
	pe = ft_findad(s1, set, 1);
	cp = (char *)malloc((ps - pe) + 1);
	if (!cp)
		return (NULL);
	while (ps < pe)
	{
		cp[i] = s1[ps];
		i++;
		ps++;
	}
	cp[i++] = '\0';
	return (cp);
}

int		main(void)
{
	char	str[] = "AABBBJJJAAA";
	char	set[] = "AB";

	printf("%s\n", ft_strtrim(str, set));
	return (0);
}
