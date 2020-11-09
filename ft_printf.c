/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 12:42:34 by amarini-          #+#    #+#             */
/*   Updated: 2020/11/09 13:54:13 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*found_args = "";
char	*specs = "cspdixX%";
int		padding = 0;

int		sort_behavior(va_list args, char *spec)
{
	char	*(add_args[])(va_list) = {};
	char	*print;
	int		result;
	int		i;

	i = 0;
	while (specs[i] != '\0')
	{
		if (specs[i] == spec[0])
		{
			print = add_flags[i](args);
			break;
		}
		i++;
	}
	if (spec[0] == 'x' || spec[0] == 'X' || spec[0] == 'd' 
		|| spec[0] == 'i' || spec[0] == 'p')
		print = flags_int(print, found_args, padding);
	else if (spec[0] == 'c' || spec[0] == 's')
		print = flags_char(print, found_args, padding);
	if (!print || print[0] == '\0')
		print = no_spec(spec);
	result = ft_strlen(print);
	ft_putstr(print);
	return (result);
}

int		check_flag(va_list args, char *str)
{
	char	*flags = "-0c*";
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		padding = (padding * 10) + (str[i] - '0');
		i++;
	}
	while (str[i] != '\0')
	{
		while (flags[j] != '\0')
		{
			if (str[i] == flags[j])
			{
				found_args = ft_join_char(found_args, str[i]);
				break;
			}
			j++;
		}
		i++;
	}
	j = 0;
	while (found_args[j] != '\0')
	{
		if (found_args[j] == '*')
			padding = va_arg(args, int);
		j++;
	}
	return (i);
}

int		ft_printf(char *str, ...)
{
	va_list		args;
	int			result;
	int			i;

	va_start(args, str);
	i = 0;
	result = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			i = check_flags(args, str[i]);
			result += sort_behavior(args, str[i]);
			i++;
		}
		else
		{
			ft_putchar(str[i]);
			result++;
		}
		i++;
	}
	return (result); 
}