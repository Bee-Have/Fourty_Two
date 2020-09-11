/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 07:42:38 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/11 10:03:25 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int		calc_prefix(char const *str, char const *set)
{
	int		length;
	int		istr;
	int		iset;
	int		diff;

	length = 0;
	istr = 0;
	while (str[istr] != '\0')
	{
		iset = 0;
		diff = 1;
		while (set[iset] != '\0')
		{
			if (str[istr] == set[iset])
			{
				length++;
				diff = 0;
			}
			iset++;
		}
		if (diff == 1)
			return (length);
		istr++;
	}
	return (length);
}

int		calc_sufix(char const *str, char const *set, int maxlen)
{
	int		length;
	int		iset;
	int		diff;

	length = 0;
	maxlen -= 1;
	while (maxlen > 0)
	{
		iset = 0;
		diff = 1;
		while (set[iset] != '\0')
		{
			if (str[maxlen] == set[iset])
			{
				length++;
				diff = 0;
			}
			iset++;
		}
		if (diff == 1)
			return (length);
		maxlen--;
	}
	return (length);
}

int		calc_len(char const *str, char const *set)
{
	int		length;

	length = 0;
	length = ft_strlen(str);
	length -= (calc_prefix(str, set) + calc_sufix(str, set, length));
	if (length <= 0)
		return (0);
	return (length);
}

char	*ft_strtrim(char const *s1m, char const *set)
{
	char	*result;
	int		length;
	int		ires;
	int		is;

	length = 0;
	ires = 0;
	is = 0;
	length = calc_len(s1m, set);
	result = (char *)malloc((length + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[length] = '\0';
	while (ires < length)
	{
		while (calc_prefix(s1m, set) > is
				|| (ft_strlen(s1m) - calc_sufix(s1m, set, ft_strlen(s1m))) < is)
			is++;
		result[ires] = s1m[is];
		ires++;
		is++;
	}
	return (result);
}
