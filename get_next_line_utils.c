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

void	fill_str(char **dst, char *src)
{
	int		i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
}

char	*ft_strjoin(char *dst, char *src)
{
	int		maxlen;
	char	*result;

	maxlen = ft_strlen(dst) + ft_strlen(src);
	result = (char *)malloc((maxlen + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[maxlen] = '\0';
	fill_str(&result, dst);
	fill_str(&result, src);
	return (result);
}
