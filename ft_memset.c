/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 10:22:02 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/01 10:24:37 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	*ft_memset(void *b, int c, size_t len)
{
	int		i;
	char	*array;

	i = 0;
	if (!b)
		return (NULL);
	array = (char *)b;
	while (i < len)
	{
		array[i] = (char *)c;
		i++;
	}
	return (array);
}
