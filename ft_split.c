/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 07:42:58 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/10 09:50:42 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int		calc_row(char const *s, char c)
{
	int		i;
	int		row;
	int		sep;

	i = 0;
	row = 0;
	if (s[i] == c)
		while (s[i] == c)
			i++;
	while (s[i] != '\0')
	{
		sep = 0;
		while (s[i] == c && s[i] != '\0')
		{
			sep++;
			i++;
		}
		if (sep > 0)
			row++;
		if (s[i] != '\0')
			i++;
	}
	if (s[0] != c || s[i - 1] != c)
		row++;
	return (row);
}

int		calc_col(char const *s, char c, int strpos)
{
	int		length;

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

int		calc_sep(char const *s, char c, int strpos)
{
	int		length;

	length = 0;
	while (s[strpos] != '\0')
	{
		if (s[strpos] != c)
			return (length);
		strpos++;
		length++;
	}
	return (length);
}

char	*fill_array(char *result, char const *s, int i, int collumn)
{
	int		icol;

	icol = 0;
	while (icol < collumn)
	{
		result[icol] = s[i];
		icol++;
		i++;
	}
	result[collumn] = '\0';
	return (result);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		irow;
	char	**result;

	i = 0;
	irow = 0;
	if (!s || !c)
		return (NULL);
	result = (char **)malloc((calc_row(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	result[calc_row(s, c)] = NULL;
	while (s[i] == c)
		i++;
	while (irow < calc_row(s, c))
	{
		result[irow] = (char *)malloc((calc_col(s, c, i) + 1) * sizeof(char));
		if (!result[irow])
			return (NULL);
		result[irow] = fill_array(result[irow], s, i, calc_col(s, c, i));
		i += calc_col(s, c, i);
		i += calc_sep(s, c, i);
		irow++;
	}
	return (result);
}
