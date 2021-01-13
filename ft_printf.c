/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 19:12:49 by amarini-          #+#    #+#             */
/*   Updated: 2021/01/13 15:13:26 by amarini-         ###   ########.fr       */
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
	list->padding = padding_register(str, i);
	flags_register(&list, str, args, i);
	(*i)--;
	list->convert = str[(*i)];
	list->print = convert_arg(str, args, *i);
	if (list->length == 0)
		list->length = ft_strlen(list->print);
	flags_managment(&list);
	ft_putstr(list->print);
	result = list->padding + list->length;
	free(list->print);
	free(list);
	return (result);
}

t_list	*init_struct(void)
{
	t_list *list;

	list = NULL;
	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->length = 0;
	list->padding = 0;
	list->neg_padding = 0;
	list->pad_char = ' ';
	list->convert = 'a';
	list->print = NULL;
	return (list);
}