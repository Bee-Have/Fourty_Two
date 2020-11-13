/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 12:42:34 by amarini-          #+#    #+#             */
/*   Updated: 2020/11/13 19:16:27 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*found_args = "";
char	*allspecs = "cspdiuxX%";
int		padding = 0;

int		sort_behavior(va_list args, char spec)
{
	char	*(*read_spec[])(va_list) = {spec_c, spec_s, spec_p, spec_di,
									spec_di, spec_u, spec_xX, spec_percentage};
	char	*print;
	int		result;
	int		i;

	i = 0;
	print = NULL;
	while (allspecs[i] != '\0')
	{
		if (spec == allspecs[i])
		{
			print = read_spec[i](args);
			break;
		}
		i++;
	}
	if (spec == 'x' || spec == 'X' || spec == 'd' 
		|| spec == 'i' || spec == 'p')
		print = flags_int(print, found_args, padding);
	else if (spec == 'c' || spec == 's')
		print = flags_char(print, found_args, padding);
	if (!print || print[0] == '\0')   
		return (0);
	else
	{
		result = ft_strlen(print);
		ft_putstr(print);
	}
	return (result);
}

int		register_flags(va_list args, char *str)
{
	char	*flags = "0-.*";
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] >= '1' && str[i] <= '9')
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
				found_args = ft_strjoin_char(found_args, str[i]);
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
	free(str);
	return (ft_strlen(found_args));
}

int		ft_printf(const char *str, ...)
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
			i += register_flags(args, ft_substr(str, i, ft_strlen((char *)str) - i));
			result += sort_behavior(args, str[i]);
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