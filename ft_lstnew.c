/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 16:43:17 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/15 09:48:20 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	char	*value;

	value = (char *)content;
	t_list *head = NULL;
	head = (t_list *)malloc(sizeof(t_list));
	if (!head)
		return (NULL);
	head->content = value;
	head->next = NULL;
	return (head);
}

int		main(void)
{
	char	*value;
	t_list	*current;

	value = "hello world";
	value = ft_strdup(value);
	current = ft_lstnew((void *)value);
	while (current->next != NULL)
	{
		printf("%s\n", (char *)current->content);
		current = current->next;
	}
	return (0);
}
