/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 07:42:00 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/14 14:47:35 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*fill_str(char const *src, char *dst, int index)
{
	int		i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[index] = src[i];
		i++;
		index++;
	}
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str = fill_str(s1, str, j);
	j += ft_strlen(s1);
	str = fill_str(s2, str, j);
	j += ft_strlen(s2);
	str[j] = '\0';
	return (str);
}
