#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		ft_calclen(char const *str, char c, int i)
{
	int		len;

	len = 0;
	while (str[i] != c && str[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

int		ft_calcheig(char const *str, char c)
{
	int		i;
	int		h;

	i = 0;
	h = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			h++;
		i++;
	}
	return (h);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		ih;
	int		il;
	int		l;
	int		h;
	char	**res;

	i = 0;
	ih = 0;
	il = 0;
	l = 0;
	h = ft_calcheig(s, c) + 1;
	res = (char **)malloc(h * (sizeof(char *)));
	if (!res)
		return (NULL);
	while (ih < h)
	{
		l = ft_calclen(s, c, i);
		res[ih] = (char *)malloc((l + 1) * sizeof(char));
		if (!res[ih])
			return(NULL);
		while (il < l)
		{
			res[ih][il] = s[i];
			i++;
			il++;
		}
		res[ih][il] = '\0';
		i++;
		ih++;
		il = 0;
	}
	res[ih] = NULL;
	return (res);
}

int		main(void)
{
	char test[] = "Hello there";
	char sep = ' ';
	char **res;
	int i = 0;
	int j = 0;

	res = ft_split(test, sep);
	while (res[i] != '\0')
	{
		printf("%s\n", res[i]);
		i++;
	}
	j++;
	return (0);
}
