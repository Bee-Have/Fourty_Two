/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 11:02:41 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/15 13:00:56 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int		main(void)
{
	//ye im being very lazy i know
	t_list current = NULL;
	t_list	*first = NULL;
	t_list	*s1 = NULL;
	t_list	*s2 = NULL;
	t_list	*s3 = NULL;
	t_list	*s4 = NULL;
	t_list	*s5 = NULL;
	t_list	*end = NULL;

	first = ft_lstnew("first");
	s1 = ft_lstnew("second");
	s2 = ft_lstnew("third");
	s3 = ft_lstnew("fourth");
	s4 = ft_lstnew("fifth");
	s5 = ft_lstnew("sixth");
	end = ft_lstnew("last");
	first->next = s1;
	s1->next = s2;
	s2->next = s3;
	s3->next = s4;
	s4->next = s5;
	s5->next = end;
	end->next = NULL;
	current = first;
	while (current->next != NULL)
	{
		printf("%s\n", current->content);
		current = current->next;
	}
	ft_lstiter(first, ft_strjoin(void *, " nyan"))
	current = first;
	while (current->next != NULL)
	{
		printf("%s\n", current->content);
		current = current->next;
	}
	return (0);
}
