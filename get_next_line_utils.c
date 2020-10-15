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

/*void	ft_bzero(char **str, int max)
{
	int		i;

	i = 0;
	while (i < max)
	{
		*str[i] = '\0';
		i++;
	}
	return ;
}*/

char	*fill_str(char **dst, char *src, int idst, int maxlen)
{
	int		i;

	i = 0;
	while (src[i] != '\0' && idst <= maxlen)
	{
		(*dst)[idst] = src[i];
		//printf("dst=[%c]\n", (*dst)[idst]);
		i++;
		idst++;
	}
	return (*dst);
}

char	*ft_strjoin(char *dst, char *src)
{
	int		i;
	int		maxlen;
	char	*result;

	i = 0;
	if (!dst || ft_strlen(dst) == 0)
		return (src);
	maxlen = ft_strlen(dst) + ft_strlen(src);
	printf("maxlen=[%d]\n", maxlen);
	result = (char *)malloc((maxlen + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[maxlen] = '\0';
	//ft_bzero(&result, maxlen);
	result = fill_str(&result, dst, i, ft_strlen(dst));
	i = ft_strlen(dst);
	result = fill_str(&result, src, i, maxlen);
	free(dst);
	return (result);
}

char	*ft_substr(char *str, int start, int len, int line)
{
	int		i;
	char	*result;

	i = 0;
	if (start > ft_strlen(str))
		return (NULL);
	if (str[start] == '\n' && line == 1)
		start++;
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
