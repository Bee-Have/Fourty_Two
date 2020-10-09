/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 11:03:00 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/22 11:19:40 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*fill_leftover(char const *src, char *dst, int index, int maxlen)
{
	int		i;

	i = 0;
	if (!src)
		return (dst);
	while (index < maxlen && src[i] != '\0')
	{
		dst[index] = src[i];
		index++;
		i++;
	}
	dst[index] = '\0';
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		maxlen;
	char	*result;

	i = 0;
	maxlen = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	result = (char *)malloc((maxlen + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[maxlen] = '\0';
	result = fill_leftover(s1, result, i, ft_strlen((char *)s1));
	i = ft_strlen(result);
	result = fill_leftover(s2, result, i, maxlen);
	return (result);
}

char	*ft_substr(char *str, unsigned int start, int len)
{
	int		i;
	char	*result;

	i = 0;
	if (len <= 0 || (len == 1 && str[start] == '\n'))
		len = 0;
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[len] = '\0';
	while (str[start] != '\0' && i < len)
	{
		result[i] = str[start];
		i++;
		start++;
	}
	return (result);
}
