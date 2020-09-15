/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 10:09:10 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/15 11:40:14 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*current;

	i = 1;
	current = lst;
	while (current->next != NULL)
	{
		i++;
		current = current->next;
	}
	return (i);
}
