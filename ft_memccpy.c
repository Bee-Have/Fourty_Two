/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 07:31:33 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/01 07:33:50 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	int		i;
	char	*cpdest;
	char	*cpsrc;

	i = 0;
	cpdest = (char *)dst;
	cpsrc = (char *)src;
	while (i <= n)
	{
		cpdest[i] = cpsrc[i];
		if (cpsrc[i] == (char)c)
			return (dst);
		i++;
	}
	return (dst);
}
