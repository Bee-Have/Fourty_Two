/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 09:46:20 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/01 09:48:52 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	int		i;
	char	*copy;

	i = 0;
	if (!s)
		return (NULL);
	copy = (char *)s;
	while (i < n)
	{
		if (copy[i] == (char)c)
			return (&cps[i]);
		i++;
	}
	return (NULL);
}
