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
	printf("%d\n", len);
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
	printf("%d, %d, %d\n", i, l, h);
	res = (char **)malloc(h * (sizeof(char *)));
	if (!res)
		return (NULL);
	printf("first malloc done\n");
	while (ih < h)
	{
		l = ft_calclen(s, c, i);
		printf("l = %d\nil = %d\n", l, il);
		res[ih] = (char *)malloc((l + 1) * sizeof(char));
		if (!res[ih])
			return(NULL);
		printf("second malloc done\n");
		while (il < l)
		{
			write(1, "test\n", 5);
			printf("%d, %c, %c\n", il, res[i][il], s[i]);
			res[ih][il] = s[i];
			printf("%c, %c\n", res[ih][il], s[i]);
			i++;
			il++;
		}
		res[ih][il] = '\0';
		i++;
		ih++;
		il = 0;
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
