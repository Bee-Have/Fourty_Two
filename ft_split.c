/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 07:42:58 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/17 12:45:55 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

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
	if (s[i - 1] != c)
		row++;
	return (row);
}

int		calc_cs(char const *s, char c, int strpos, int which)
{
	int		length;

	length = 0;
	while (s[strpos] != '\0')
	{
		if (which == 0)
		{
			if (s[strpos] == c)
				return (length);
		}
		if (which == 1)
		{
			if (s[strpos] != c)
				return (length);
		}
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

char	**free_everything(char **result)
{
	int		irow;

	irow = 0;
	while (result[irow] != NULL)
	{
		free(result[irow]);
		result[irow] = NULL;
		irow++;
	}
	free(result);
	return (NULL);
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
		result[irow] = (char *)malloc((calc_cs(s, c, i, 0) + 1) * sizeof(char));
		if (!result[irow])
			return (free_everything(result));
		result[irow] = fill_array(result[irow], s, i, calc_cs(s, c, i, 0));
		i += calc_cs(s, c, i, 0) + calc_cs(s, c, (i + calc_cs(s, c, i, 0)), 1);
		irow++;
	}
	return (result);
}
