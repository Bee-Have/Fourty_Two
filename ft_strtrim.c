/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 07:42:38 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/01 07:42:40 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int		ft_findadr(const char *s1, const char *set, int bl)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (bl > 0)
	{
		while (s1[j] != '\0')
			j++;
		j--;
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
	ps = ft_findadr(s1, set, 0);
	pe = ft_findadr(s1, set, 1);
	cp = (char *)malloc((pe - ps) + 1);
	if (!cp)
		return (NULL);
	while (ps <= pe)
	{
		cp[i] = s1[ps];
		i++;
		ps++;
	}
	cp[i++] = '\0';
	return (cp);
}
