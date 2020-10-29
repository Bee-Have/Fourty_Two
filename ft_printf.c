/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 15:51:24 by amarini-          #+#    #+#             */
/*   Updated: 2020/10/29 13:58:52 by amarini-         ###   ########.fr       */
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

char	*ft_strjoin(char *dst, char src)
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
	return (result);
}

int		sort_flags(va_list args, char spec, char *flags)
{
	int		(add_flags)(char *, char *) = {};
	int		result;
	char	*print;

	result = 0;
	if (spec == 'd' || spec == 'i')
	{
		print = 
	}
	return (result);
}

int		ft_printf(const char *str, ...)
{
	va_list		args;
	char		*specs[2];
	char		found_args;
	int			i;
	int			j;
	int			i_spec;
	int			length;

	i = 0;
	j = 0;
	i_spec = 0;
	length = 0;
	va_start(args, str);
	specs[0] = ft_strcpy("-0.*");
	specs[1] = ft_strcpy("cspdiuxxX%");
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			while (specs[i_spec] && specs[i_spec][j] != '0')
			{
				if (str[i] == specs[i_spec][j])
				{
					if (specs[i_spec] == 0)
						found_args = ft_strjoin(found_args, specs[j]);
					else
					{
						length = sort_flags(args, str[i], found_args);
						break;
					}
					i++;
					j = 0;
				}
				j++;
			}
			i++;
			j = 0;
			i_spec++;
		}
	}
	return (length);
}