#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	calc_row(char const *s, char c)
{
	int	i;
	int	row;

	row = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			row++;
		i++;
	}
	return (row);
}

int	calc_col(char const *s, char c, int strpos)
{
	int	length;

	length = 0;
	while (s[strpos] != '\0')
	{
		if (s[strpos] == c)
			return (length);
		strpos++;
		length++;
	}
	return (length);
}

char	*fill_array(char *result, char const *s, int i, int collumn)
{
	int	icol;

	icol = 0;
	while (icol <= collumn)
	{
		result[icol] = s[i];
		icol++;
		i++;
	}
	result[icol] = '\0';
	return (result);
}

char	**ft_split(char const *s, char c)
{
	int	i;
	int	irow;
	char	**result;
	
	i = 0;
	irow = 0;
	if (!s || !c)
		return (NULL);
	result = (char **)malloc((calc_row(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	while (irow <= calc_row(s, c))
	{
		result[irow] = (char *)malloc((calc_col(s, c, i) + 1) * sizeof(char));
		if (!result[irow])
			return (NULL);
		result[irow] = fill_array(result[irow], s, i, calc_col(s, c, i));
		i = i + (calc_col(s, c, i) + 1);
		irow++;
	}

	result[irow] = '\0';
	return (result);
}

int	main(void)
{
	char split = ' ';
	char *chaine = "hello this is duck";
	char **result;

	result = ft_split(chaine, split);
	printf("%s\n%s\n%s\n%s\n", result[0], result[1], result[2], result[3]);
	return (0);
}
