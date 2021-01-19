/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_managment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 14:51:49 by amarini-          #+#    #+#             */
/*   Updated: 2021/01/19 16:57:28 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	padding_register(char *str, int *i, t_list **list)
{
	int		result;

	result = 0;
	if (str[(*i)] == '-')
	{
		(*list)->neg_padding == 1;
		(*list)->pad_char = ' ';
		(*i)++;
	}
	if (str[(*i)] == '0')
		return ;
	while (str[(*i)] != '\0')
	{
		if (str[(*i)] >= '0' && str[(*i)] <= '9')
			result = (result * 10) + (str[(*i)] - '0');
		else
		{
			(*list)->padding = result;
			return ;
		}
		(*i)++;
	}
	(*list)->padding = result;
}

void	flags_register(t_list **list, char *str, va_list args, int *i)
{
	while (str[(*i)] != '\0')
	{
		if (str[(*i)] == '-')
		{
			(*list)->neg_padding = 1;
			(*list)->pad_char = ' ';
		}
		else if (str[(*i)] == '*')
			(*list)->padding = va_arg(args, int);
		else if (str[(*i)] == '0')
		{
			(*list)->pad_char = '0';
			(*list)->padding = register_padding_flags(str, i, list);
		}
		else if (str[(*i)] == '.')
		{
			(*list)->length = register_padding_flags(str, i, list);
			if (str[(*i)] == '*')
				(*list)->length = va_arg(args, int);
			if ((*list)->length < 0)
				(*list)->length = 0;
		}
		else
			return ;
		(*i)++;
	}
}

char	*convert_arg(char *str, va_list args, int index)
{
	char	*result;

	if (str[index] == 'c' || str[index] == '%')
		result = char_to_string(va_arg(args, int));
	else if (str[index] == 's')
		result = str_cpy(va_arg(args, char *));
	else if (str[index] == 'p')
		result = address_to_string(va_arg(args, int));
	else if (str[index] == 'd' || str[index] == 'i')
		result = int_to_string(va_arg(args, int));
	else if (str[index] == 'u')
		result = int_to_string(va_arg(args, unsigned int));
	else if (str[index] == 'x' || str[index] == 'X')
	{
		result = hexa_to_string(va_arg(args, unsigned int));
		if (str[index] == 'X')
			result = ft_toupper(result);
	}
	else
		return (NULL);
	return (result);
}

void	flags_managment(t_list **list)
{
	char	*copy;
	char	*extention;

	if (!(*list)->print)
		return ;
	copy = str_cpy((*list)->print);
	if ((*list)->convert == 's' && (*list)->length < ft_strlen(copy))
		(*list)->print = str_trim((*list)->print, (*list)->length);
	else if ((*list)->convert != 's' && (*list)->convert != 'c' && (*list)->length > ft_strlen(copy))
	{
		extention = make_extention('0', (*list)->length - ft_strlen(copy), (*list)->convert);
		(*list)->print = ft_strjoin(extention, (*list)->print);
	}
	if ((*list)->padding != 0)
	{
		(*list)->padding = calculate_padding((*list)->padding, (*list)->length);
		(*list)->length = ft_strlen(copy) + (*list)->padding;
		extention = make_extention((*list)->pad_char, (*list)->padding, (*list)->convert);
		if ((*list)->neg_padding == 0)
			(*list)->print = ft_strjoin(extention, (*list)->print);
		else if ((*list)->neg_padding == 1)
			(*list)->print = ft_strjoin((*list)->print, extention);
	}
	(*list)->length = ft_strlen((*list)->print);
	free(copy);
}