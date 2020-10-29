/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 15:51:24 by amarini-          #+#    #+#             */
/*   Updated: 2020/10/29 17:40:03 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		sort_flags(va_list args, char spec, char *flags, int padding)
{
	int		(add_flags)(char **, va_list) = {};
	int		result;
	char	*print;
	int		i;

	result = 0;
	i = 0;
	while (flags[i] != '\0')
	{
		if (flags[i] == '*')
			padding = va_arg(args, int);
		i++;
	}
	i = 0;
	if (spec == 'd' || spec == 'i')
	{
		print = ft_itoa(va_arg(args, int));
		print = flags_int(print, flags, padding);
	}
	else if (spec == 'x' || spec == 'X')
	{
		print = ft_itoa_base(va_arg(args, unsigned int), 16);
		if (spec == 'X')
		{
			while (print[i] != '\0')
			{
				if (print[i] >= 'a' && print[i] <= 'z')
					print[i] -= 32;
				i++;
			}
		}
		print = flags_int(print, flags, padding);
	}
	else if (spec == 'p')
	{
		print = ft_itoa_base(va_arg(args, unsigned int), 16);
		print = ft_strjoin("0x", print);
	}
	result = ft_strlen(print);
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
	int			padding;
	int			length;

	i = 0;
	j = 0;
	i_spec = 0;
	length = 0;
	padding = 0;
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
				if (str[i] > '0' && str[i] <= '9')
					padding = (padding * 10) + (str[i] - '0');
				if (str[i] == specs[i_spec][j])
				{
					if (specs[i_spec] == 0)
					{
						//this is no good,
						//specs will be added entirely and not only the char
						found_args = ft_strjoin(found_args, (char)specs[j]);
					}
					else
					{
						length = sort_flags(args, str[i], found_args, padding);
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