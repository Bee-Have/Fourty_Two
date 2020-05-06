#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		ft_calclen(char const *str, char c, int maxlen, int i)
{
	int		len;

	len = 0;
	while (str[i] != c && str[i] != '\0')
	{
		len++;
		i++;
	}
	if (len > maxlen)
		maxlen = len;
	if (str[i] != '\0')
		return (ft_calclen(str, c, maxlen, (i + 1)));
	return (maxlen);
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
	int		maxl;
	int		l;
	int		h;
	int		totlen;
	char	**res;

	i = 0;
	maxl = ft_calclen(s, c, 0, 0) + 1;
	l = maxl;
	h = ft_calcheig(s, c);
	totlen = (sizeof(char *) * (h + 1)) + (sizeof(char) * (l + 1) * h);
	while (s[i] != '\0')
		i++;
	printf("%d, %d, %d, %d\n", i, maxl, l, h);
	res = (char **)malloc(totlen);
	if (!res)
		return (NULL);
	while (h >= 0)
	{
		res[h][l] = '\0';
		i--;
		printf("%c\n", s[i]);
		while (l >= 0)
		{
			res[h][l] = s[i];
			printf("%c", res[h][l]);
			l--;
			i--;
		}
		printf("\n");
		l = maxl;
		i--;
		h--;
	}
	return (res);
}

int		main(void)
{
	char	test[] = "Hello general";
	char	**res;

	printf("%s\n", test);
	res = ft_split(test, ' ');
}
