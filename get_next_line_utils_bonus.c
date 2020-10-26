/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 09:26:57 by amarini-          #+#    #+#             */
/*   Updated: 2020/10/26 17:01:07 by amarini-         ###   ########.fr       */
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

char	*ft_strncpy(char *dst, char *src, int idst)
{
	int		i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[idst] = src[i];
		i++;
		idst++;
	}
	return (dst);
}

char	*ft_strjoin(char *dst, char *src)
{
	int		i;
	int		maxlen;
	char	*result;

	i = 0;
	if (!dst || ft_strlen(dst) == 0)
		maxlen = ft_strlen(src);
	else
		maxlen = ft_strlen(dst) + ft_strlen(src);
	result = (char *)malloc((maxlen + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[maxlen] = '\0';
	if (dst || ft_strlen(dst) != 0)
	{
		result = ft_strncpy(result, dst, i);
		i = ft_strlen(dst);
	}
	result = ft_strncpy(result, src, i);
	free(dst);
	return (result);
}

char	*ft_substr(char *str, int start, int len, int line)
{
	int		i;
	char	*result;

	i = 0;
	if (start > ft_strlen(str))
		return (str);
	if (line == 0 && start == 0)
	{
		start = ft_strlen(str) - 1;
		len = 0;
	}
	if (str[start] == '\n' && line == 1)
		start++;
	if (!(result = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	result[len] = '\0';
	while (str[start] != '\0' && i < len)
	{
		result[i] = str[start];
		i++;
		start++;
	}
	if (line == 0)
		free(str);
	return (result);
}
