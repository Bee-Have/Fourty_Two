/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 09:46:20 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/11 15:40:06 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int		i;
	char				*copy;

	i = 0;
	copy = (char *)s;
	while (i < n)
	{
		if (copy[i] == (char)c)
			return (&copy[i]);
		i++;
	}
	return (NULL);
}
