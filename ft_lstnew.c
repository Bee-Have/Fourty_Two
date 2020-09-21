/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 16:43:17 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/15 11:07:10 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

t_list		*ft_lstnew(void *content)
{
	char	*value;
	t_list	*head;

	value = (char *)content;
	head = NULL;
	head = (t_list *)malloc(sizeof(t_list));
	if (!head)
		return (NULL);
	head->content = value;
	head->next = NULL;
	return (head);
}
