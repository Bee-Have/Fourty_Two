/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 15:51:24 by amarini-          #+#    #+#             */
/*   Updated: 2020/10/23 16:15:04 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	va_list		args;
	char		*result;
	int			i;
	int			count;
	
	va_start(args, str);
	result = NULL;
	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 'c')
			{
			}
			else if (str[i] == 's')
			{
			}
			else if (str[i] == 'p')
			{
			}
			else if (str[i] == 'd' || str[i] == 'i')
			{
			}
			else if (str[i] == 'u')
			{
			}
			else if (str[i] == 'x' || str[i] == 'X')
			{
			}
			else if (str[i] == '%')
			{
			}
			else if (str[i] == '-')
			{
			}
			else if (str[i] == '0')
			{
			}
			else if (str[i] == '.')
			{
			}
			else if (str[i] == '*')
			{
			}
		}
		else
		{
			
		}		
		i++;
	}
}