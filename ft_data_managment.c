/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_managment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 14:51:49 by amarini-          #+#    #+#             */
/*   Updated: 2021/01/23 14:46:33 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		padding_register(char *str, int *i, t_list **list, va_list args)
{
	int		result;

	result = 0;
	//(*i)++;
	if (str[(*i)] == '-')
	{
		(*list)->neg_padding = 1;
		(*list)->pad_char = ' ';
		(*i)++;
	}
	if (str[(*i)] == '0')
	{
		(*i)++;
		if (str[(*i)] <= '0' && str[(*i)] >= '9')
			return (0);
	}
	if (str[(*i)] == '*')
	{
		result = va_arg(args, int);
		(*i)++;
	}
	else
		while (str[(*i)] != '\0' && str[(*i)] >= '0' && str[(*i)] <= '9')
		{
			result = (result * 10) + (str[(*i)] - '0');
			(*i)++;
		}
	return (result);
}

void	flags_register(t_list **list, char *str, va_list args, int *i)
{
	while (str[(*i)] != '\0')
	{
		if (str[(*i)] == '-')
		{
			(*list)->padding = padding_register(str, i, list, args);
			(*i)--;
		}
		else if (str[(*i)] == '0')
		{
			(*list)->pad_char = '0';
			(*list)->padding = padding_register(str, i, list, args);
			(*i)--;
		}
		else if (str[(*i)] == '.')
		{
			(*list)->len_flag = 1;
			(*i)++;
			(*list)->length = padding_register(str, i, list, args);
			(*i)--;
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