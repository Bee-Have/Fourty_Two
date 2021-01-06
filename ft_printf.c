/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 19:12:49 by amarini-          #+#    #+#             */
/*   Updated: 2021/01/06 21:41:53 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	va_list args;
	va_start(args, str);
}

t_list	init_struct(void)
{
	t_list *list;

	list = NULL;
	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return;
	list->length = 0;
	list->padding = 0;
	list->neg_padding = 0;
	list->zero = 0;
	list->neg = 0;
	list->print = NULL;
}

