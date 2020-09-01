/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 09:11:14 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/01 09:13:33 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_bzero(void *s, size_t n)
{
	int		i;
	int		*tab;

	i = 0;
	tab = (char *)s;
	while (i <= n)
	{
		tab[i] = (char)'\0';
		i++;
	}
}
