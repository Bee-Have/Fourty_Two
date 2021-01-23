/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 19:12:49 by amarini-          #+#    #+#             */
/*   Updated: 2021/01/23 18:07:19 by amarini-         ###   ########.fr       */
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
	return (result);
}

int	str_data_managment(char *str, int *i, va_list args)
{
	t_list	*list;
	int		result;

	result = 0;
	list = init_struct();
	list->padding = padding_register(str, i, &list, args);
	flags_register(&list, str, args, i);
	list->convert = str[(*i)];
	if ((list->len_flag == 1 && list->neg_padding == 1) || list->problem == 1)
		return (return_to_percent(str, i, &list));
	list->print = convert_arg(str, args, *i);
	if (list->print != NULL && list->length == 0)
		list->length = ft_strlen(list->print);
	if (list->padding <= 0)
	{
		list->padding = list->padding * -1;
		list->neg_padding = 1;
	}
	flags_managment(&list);
	if (list->print)
		ft_putstr(list->print);
	else
		return (return_to_percent(str, i, &list));
	result = list->length;
	ft_free_list(&list);
	return (result);
}