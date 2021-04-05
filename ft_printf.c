/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 19:12:49 by amarini-          #+#    #+#             */
/*   Updated: 2021/04/05 10:17:04 by amarini-         ###   ########.fr       */
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
		{
			ft_putstr(rest);
			result += data_managment((char*)str, &i, args) + ft_len(rest);
			rest = fill_str(rest, '\0', ft_len((char *)str));
		}
		else
			rest[ft_len(rest)] = str[i];
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

	(*i)++;
	result = 0;
	list = init_struct();
	list->padding = padding_register(str, i, &list, args);
	flags_register(&list, str, args, i);
	list->convert = str[(*i)];
	if (list->problem == 1 || str_cmp(list->convert, NULL, "cspdiuxX") == 0
		|| list->convert == '%')
		return (return_to_percent(str, i, &list));
	list->print = convert_arg(str, args, *i);
	if (str_cmp(0, list->print, "(null)") == 0 && list->len_flag == 1
		&& list->length < ft_len(list->print))
		list->print = strtrim(list->print, 0, 0);
	if (list->length != ft_len(list->print) && list->len_flag == 0)
		list->length = ft_len(list->print);
	flags_managment(&list);
	if (list->print[0] == '\0' && list->convert != 'c')
		list->length = 0;
	ft_putstr(list->print);
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
		ft_putstr(rest);
	}
	free(rest);
	return (result);
}
