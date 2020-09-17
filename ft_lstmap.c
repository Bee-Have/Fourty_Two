/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 10:17:09 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/16 16:01:59 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*head;

	if (!lst)
		return (NULL);
	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	head = new;
	while (lst->next != NULL)
	{
		new->content = f(lst->content);
		new->next = (t_list *)malloc(sizeof(t_list));
		if (!new->next)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		new = new->next;
		lst = lst->next;
	}
	new->content = f(lst->content);
	new->next = NULL;
	return (head);
}
