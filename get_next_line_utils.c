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
	while (str[i] != '\0')
		i++;
	return (i);
}

void	fill_str(char **dst, char *src, int idst)
{
	int		i;

	i = 0;
	while (src[i] != '\0')
	{
		*dst[idst] = src[i];
		i++;
		idst++;
	}
	idst -= 1;
}

char	*ft_strjoin(char *dst, char *src)
{
	int		i;
	int		maxlen;
	char	*result;

	i = 0;
	maxlen = ft_strlen(dst) + ft_strlen(src);
	result = (char *)malloc((maxlen + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[maxlen] = '\0';
	fill_str(&result, dst, i);
	i += ft_strlen(result);
	fill_str(&result, src, i);
	return (result);
}

char	*ft_substr(char *str, int start, int len)
{
	int		i;
	char	*result;

	i = 0;
	if (!str)
		return (NULL);
	if (ft_strlen(str) == 0 || start >= ft_strlen(str))
		return (str);
	if (str[start] == '\n')
		start++;
	if (ft_strlen(str) < len)
		result = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	else
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
