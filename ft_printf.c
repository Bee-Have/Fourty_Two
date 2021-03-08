/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 19:12:49 by amarini-          #+#    #+#             */
/*   Updated: 2021/03/08 14:36:43 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	va_list args;
	char	*rest;
	int		result;
	int		i;
	int		j;
	
	va_start(args, str);
	result = 0;
	rest = (char *)malloc((ft_strlen((char *)str) + 1) * sizeof(char));
	if (!rest)
		return (0);
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			rest[j++] = '\0';
			ft_putstr(rest);
			rest = fill_str(rest, '\0', ft_strlen((char *)str));
			j = 0;
			i++;
			result += str_data_managment((char *)str, &i, args);
		}
		else
		{
			rest[j] = str[i];
			j++;
			result++;
		}
		i++;
	}
	rest[j] = '\0';
	if (rest[0] != '\0')
		ft_putstr(rest);
	free(rest);
	va_end(args);
	return (result);
}

int		str_data_managment(char *str, int *i, va_list args)
{
	t_list	*list;
	int		result;

	result = 0;
	list = init_struct();
	list->padding = padding_register(str, i, &list, args);
	flags_register(&list, str, args, i);
	list->convert = str[(*i)];
	if (ft_str_cmp(list->convert, NULL, "pdi") == 1 && list->len_flag == 1 && list->neg_padding == 0)
		list->pad_char = '0';
	if (list->problem == 1 && list->convert == 'c')
		list->problem = 0;
	if (list->problem == 1 || list->convert == '%')
		return (return_to_percent(str, i, &list));
	list->print = convert_arg(str, args, *i);
	if (ft_str_cmp(0, list->print, "(null)") == 0 && list->len_flag == 1 && list->length < ft_strlen(list->print))
		list->print = str_trim(list->print, 0, 0);
	if (list->print != NULL && list->length != ft_strlen(list->print) && list->len_flag == 0)
		list->length = ft_strlen(list->print);
	flags_managment(&list);
	if (list->print)
		ft_putstr(list->print);
	result = list->length;
	ft_free_list(&list);
	return (result);
}