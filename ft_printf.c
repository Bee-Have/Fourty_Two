/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 19:12:49 by amarini-          #+#    #+#             */
/*   Updated: 2021/04/06 17:53:24 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	va_list args;
	char	*rest;
	int		result;
	int		i;

	va_start(args, str);
	result = 0;
	i = 0;
	rest = str_cpy((char *)str);
	rest = fill_str(rest, '\0', ft_len((char *)str));
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			result += analyse_behavior((char *)str, &rest, &i, args);
		else
			rest[ft_len(rest)] = str[i];
		if (i < ft_len((char *)str))
			i++;
	}
	result += end_rest(rest);
	va_end(args);
	return (result);
}

int		data_managment(char *str, int *i, va_list args)
{
	t_list	*list;
	int		result;

	result = 0;
	list = init_struct();
	list->padding = padding_register(str, i, &list, args);
	flags_register(&list, str, args, i);
	if (str_cmp(str[(*i)], NULL, "cspdiuxX%") == 0)
		while (str_cmp(str[(*i)], NULL, "%-0.*123456789") == 0)
			(*i)--;
	list->convert = str[(*i)];
	list->print = convert_arg(str, args, *i);
	if (list->convert == 'c' && list->print[0] == '\0')
	{
		list->null_char[0] = 1;
		list->print[0] = 'N';
	}
	if (list->length != ft_len(list->print) && list->len_flag == 0)
		list->length = ft_len(list->print);
	flags_managment(&list);
	if (list->print[0] == '\0' && list->convert != 'c')
		list->length = 0;
	if (list->null_char[0] == 1)
		list->null_char[1] = find_null_char(list->print);
	ft_putstr(list->print, list->null_char);
	result = list->length;
	ft_free_list(&list);
	return (result);
}

int		end_rest(char *rest)
{
	int		result;

	result = 0;
	if (rest[0] != '\0')
	{
		result = ft_len(rest);
		ft_putstr(rest, NULL);
	}
	free(rest);
	return (result);
}

int		find_null_char(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'N')
			return (i);
		i++;
	}
	return (0);
}

int		analyse_behavior(char *str, char **rest, int *i, va_list args)
{
	int		result;

	result = 0;
	(*i)++;
	ft_putstr((*rest), NULL);
	if (str_cmp(str[(*i)], NULL, "cspdiuxX%-0.*123456789") == 1)
		result += data_managment(str, i, args) + ft_len((*rest));
	else if ((*i) > 1)
		(*i)--;
	else
		(*rest)[ft_len((*rest))] = str[(*i)];
	(*rest) = fill_str((*rest), '\0', ft_len((char *)str));
	return (result);
}
