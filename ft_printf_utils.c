/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 17:15:19 by amarini-          #+#    #+#             */
/*   Updated: 2020/11/09 13:53:36 by amarini-         ###   ########.fr       */
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

char	*ft_strcpy(char *str)
{
	int		i;
	char	*result;

	i = 0;
	result = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[ft_strlen(str)] = '\0';
	while (str[i] != '\0')
	{
		result[i] = str[i];
		i++;
	}
	return (result);
}

char	*ft_strjoin(char *dst, char *src)
{
	char	*result;
	int		j;
	int		i;
	int		len;

	if (!dst)
		return (src);
	i = 0;
	j = 0;
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
	return (result);
}

void	ft_putchar(char c)
{
	write(1, c, 1);
}

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

//the functions after this are for the tests i am conducting

char	*ft_strjoin_char(char *str, char c)
{
	char	*result;
	int		i;

	i = 0;
	result = (char *)malloc((ft_strlen(str) + 2) * sizeof(char));
	if (!result)
		return (NULL);
	result[ft_strlen(str) + 1] = '\0';
	while (str[i] != '\0')
	{
		result[i] = str[i];
		i++;
	}
	result[i] = c;
	return (result);
}

char	*no_spec(char *str)
{
	char	*result;
	int		length;
	int		i;
	
	length = 0;
	i = 0;
	while (str[i] != '\0' && str[i] != '%')
		length++;
	result = (char *)malloc((length + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[length] = '\0';
	while (i < length)
	{
		result[i] = str[i];
		i++;
	}
	return (result);
}
