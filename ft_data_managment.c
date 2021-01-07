/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_managment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 14:51:49 by amarini-          #+#    #+#             */
/*   Updated: 2021/01/07 18:07:11 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	padding_register(char *str, int *i)
{
	int		result;

	result = 0;
	while (str[(*i)] != '\0')
	{
		if (str[(*i)] >= '0' && str[(*i)] <= '9')
			result = (result * 10) + (str[(*i)] - '0');
		else
			return (result);
		(*i)++;
	}
	return (result);
}

t_list	*flags_register(t_list *list, char *str, va_list args, int *i)
{
	while (str[(*i)] != '\0')
	{
		if (str[(*i)] == '-')
			list->neg_padding = 1;
		else if (str[(*i)] == '0')
			list->pad_char = '0';
		else if (str[(*i)] == '.')
		{
			i++;
			while (str[(*i)] >= '0' && str[(*i)] <= '9')
			{
				list->length = (list->length * 10) + (str[(*i)] - '0');
				i++;
			}
		}
		else if (str[(*i)] == '*')
			list->padding = va_arg(args, int);
		else
			return (NULL);
		(*i)++;
	}
	return (list);
}

t_list	convert_arg(char *str, va_list args)
{
	
}