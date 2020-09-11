/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 09:11:14 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/11 11:57:13 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned int		i;
	char				*tab;

	i = 0;
	tab = (char *)s;
	if (n == 0)
		return ;
	while (i < n)
	{
		tab[i] = '\0';
		i++;
	}
}
