/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 15:51:24 by amarini-          #+#    #+#             */
/*   Updated: 2020/10/28 17:47:48 by amarini-         ###   ########.fr       */
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

void	ft_putstr(char *str)
{
	int		length;

	length = ft_strlen(str);
	write(1, str, length);
}

int		ft_printf(const char *str, ...)
{
	va_list		args;
	char		result;
	char		*convert;
	char		*flags;
	int			i;
	int			j;

	va_start(args, str);
	result = NULL;
	convert = ft_strcpy("cspdiuxX%");
	flags = ft_strcpy("-0.*");
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			while (flags[j] != '\0')
			{
				if (str[i] == flags[j])
				{

					i++;
				}
			}
			j = 0;
			while (convert[j] != '\0' && convert[j] != str[i])
				j++;
			if (convert[j] == str[i])
			{
				
			}
		}
	}
	ft_putstr(result);
	return (ft_strlen(result));
}