/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 21:49:48 by amarini-          #+#    #+#             */
/*   Updated: 2021/01/14 15:21:30 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*fill_str(char *str, char fill, int length)
{
	int		i;

	i = 0;
	str[length] = '\0';
	while (i < length)
	{
		str[i] = fill;
		i++;
	}
	return (str);
}

char	*str_cpy(char *content)
{
	char	*result;
	int		length;
	int		i;

	length = ft_strlen(content);
	i = 0;
	result = (char *)malloc((length + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[length] = '\0';
	while (i < length)
	{
		result[i] = content[i];
		i++;
	}
	return (result);
}

char	*ft_strjoin(char *dst, char *src)
{
	char	*result;
	int		i;
	int		len;

	if (!dst)
		return (src);
	i = 0;
	len = ft_strlen(dst) + ft_strlen(src);
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[len] = '\0';
	while (dst[i] != '\0')
	{
		result[i] = dst[i];
		i++;
	}
	while (i < len)
	{
		result[i] = src[i - ft_strlen(dst)];
		i++;
	}
	free(dst);
	free(src);
	return (result);
}