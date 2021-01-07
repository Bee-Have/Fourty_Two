/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 19:12:49 by amarini-          #+#    #+#             */
/*   Updated: 2021/01/07 18:06:47 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	va_list args;
	char	*rest;
	int		i;
	int		j;
	
	va_start(args, str);
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
			rest = empty_str(rest);
			j = 0;
			i++;
			str_data_managment(str_trim((char *)str, i), args);
		}
		else
		{
			rest[j] = str[i];
			j++;
		}
		i++;
	}
	free(rest);
}

void	str_data_managment(char *str, va_list args)
{
	t_list	*list;
	int		i;

	i = 0;
	list = init_struct();
	list->padding = padding_register(str, &i);
	list = flags_register(list, str, args, &i);
	return ;
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
	list->print = NULL;
	return (list);
}