/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 07:29:08 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/01 07:33:10 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	*ft_memset(void *b, int c, size_t len)
{
	int		i;
	char	*tab;

	tab = (char *)b;
	i = 0;
	while (i < len)
	{
		tab[i] = (char)c;
		i++;
	}
	return (b);
}
