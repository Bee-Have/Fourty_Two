/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 10:22:02 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/11 11:39:54 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int		i;
	char				*array;
	unsigned char		character;

	i = 0;
	character = (unsigned char)c;
	array = (char *)b;
	while (i < len)
	{
		array[i] = character;
		i++;
	}
	return (array);
}
