/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 07:32:15 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/01 07:34:38 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	int		i;
	char	*cps;

	i = 0;
	cps = (char *)s;
	while (i < n)
	{
		if (cps[i] == (char)c)
			return (&cps[i]);
		i++;
	}
	return (NULL);
}
