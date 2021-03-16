/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_managment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 14:51:49 by amarini-          #+#    #+#             */
/*   Updated: 2021/03/16 16:39:45 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		padding_register(char *str, int *i, t_list **list, va_list args)
{
	int		result;

	result = 0;
	register_negative_padding(str, i, list, &result);
	if (str[(*i)] == '0')
	{
		(*i)++;
		if (str[(*i)] < '0' || str[(*i)] > '9')
		{
			(*i)--;
			return (0);
		}
		else if ((*list)->neg_padding == 0)
			(*list)->pad_char = '0';
	}
	if (str[(*i)] == '*')
	{
		result = va_arg(args, int);
		(*i)++;
		register_negative_padding(str, i, list, &result);
	}
	else
	{
		while (str[(*i)] != '\0' && str[(*i)] >= '0' && str[(*i)] <= '9')
		{
			result = (result * 10) + (str[(*i)] - '0');
			(*i)++;
		}
	}
	return (result);
}

void	flags_register(t_list **list, char *str, va_list args, int *i)
{
	while (str[(*i)] != '\0')
	{
		if (str[(*i)] == '-')
		{
			if ((*list)->len_flag == 1)
			{
				(*list)->neg_len = 1;
				(*list)->problem = 1;
			}
			(*list)->padding = padding_register(str, i, list, args);
		}
		else if (str[(*i)] == '0')
		{
			if ((*list)->len_flag == 1 && (*list)->length != 0)
				(*list)->problem = 1;
			(*list)->pad_char = '0';
			(*i)++;
			(*list)->padding = padding_register(str, i, list, args);
			register_negative_padding(str, i, list, &(*list)->padding);
			(*i)--;
		}
		else if (str[(*i)] == '.')
		{
			(*list)->len_flag = 1;
			(*i)++;
			(*list)->length = padding_register(str, i, list, args);
			if (ft_str_cmp(str[(*i)], NULL, "cspdiuxX%") == 1 || (*list)->length != 0)
				(*i)--;
			if ((*list)->pad_char == '0')
				(*list)->pad_char = ' ';
		}
		else if (str[(*i)] == '*')
		{
			(*list)->problem = 1;
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
		result = address_to_string(va_arg(args, void *));
	else if (str[index] == 'd' || str[index] == 'i')
		result = int_to_string(va_arg(args, int));
	else if (str[index] == 'u')
		result = hexa_to_string(va_arg(args, unsigned int), 10);
	else if (str[index] == 'x' || str[index] == 'X')
	{
		result = hexa_to_string(va_arg(args, unsigned int), 16);
		if (str[index] == 'X')
			result = ft_toupper(result);
	}
	else
		return (NULL);
	return (result);
}

void	flags_managment(t_list **list)
{
	char	*extention;
	char	extention_char;
	int		prefix_used;

	prefix_used = 0;
	if (!(*list)->print)
		return ;
	if (ft_str_cmp((*list)->convert, NULL, "di") == 1 && (*list)->print[0] == '-')
	{
		free((*list)->prefix);
		(*list)->prefix = str_cpy("-");
		(*list)->print = str_trim((*list)->print, ft_strlen((*list)->print) - 1, 1);
	}
	extention_char = (*list)->pad_char;
	if ((*list)->convert == 's' && (*list)->length < ft_strlen((*list)->print) && (*list)->len_flag == 1 && (*list)->length >= 0)
		(*list)->print = str_trim((*list)->print, (*list)->length, 0);
	else if ((*list)->convert != 'c' && (*list)->convert != 's' && (*list)->len_flag == 1 && (*list)->neg_len == 0)
	{
		if ((*list)->length == 0 && ft_strlen((*list)->print) <= 1 && (*list)->print[0] == '0')
			(*list)->print = str_trim((*list)->print, 0, 0);
		else if ((*list)->length > ft_strlen((*list)->print))
		{
			if ((*list)->pad_char == ' ')
				extention_char = '0';
			extention = make_extention(extention_char, (*list)->length - ft_strlen((*list)->print), (*list)->convert);
			(*list)->print = ft_strjoin(extention, (*list)->print);
		}
	}
	if ((*list)->convert == 'p' || (ft_str_cmp((*list)->convert, NULL, "di") == 1 && ((*list)->prefix[0] == '-')
			&& (*list)->pad_char == ' ' /*&& (*list)->len_flag == 0)*/))
	{
		(*list)->print = ft_strjoin((*list)->prefix, (*list)->print);
		prefix_used = 1;
	}
	extention_char = (*list)->pad_char;
	if ((*list)->padding > 0)
	{
		if (prefix_used == 0 && (*list)->prefix[0] == '-')
			(*list)->padding = (*list)->padding - 1;
		(*list)->padding = calculate_padding((*list)->padding, ft_strlen((*list)->print));
		(*list)->length = ft_strlen((*list)->print) + (*list)->padding;
		extention = make_extention(extention_char, (*list)->padding, (*list)->convert);
		if ((*list)->neg_padding == 0)
			(*list)->print = ft_strjoin(extention, (*list)->print);
		else if ((*list)->neg_padding == 1)
			(*list)->print = ft_strjoin((*list)->print, extention);
	}
	if (prefix_used == 0 && ((*list)->convert == 'p' ||
		(ft_str_cmp((*list)->convert, NULL, "di") == 1 && (*list)->prefix[0] == '-')))
	{
		(*list)->print = ft_strjoin((*list)->prefix, (*list)->print);
		prefix_used = 1;
	}
	if (prefix_used == 0)
		free((*list)->prefix);
	(*list)->length = ft_strlen((*list)->print);
	if ((*list)->print && (*list)->length == 0 && (*list)->convert != 's')
		(*list)->length = 1;
}