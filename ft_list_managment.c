/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_managment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 21:49:48 by amarini-          #+#    #+#             */
/*   Updated: 2021/01/22 15:54:43 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list	*init_struct(void)
{
	t_list *list;

	list = NULL;
	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->length = 0;
	list->len_flag = 0;
	list->padding = 0;
	list->neg_padding = 0;
	list->pad_char = ' ';
	list->convert = 'a';
	list->print = NULL;
	return (list);
}

void	ft_free_list(t_list **list)
{
	free((*list)->print);
	free((*list));
}