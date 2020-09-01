/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 09:55:46 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/01 09:58:59 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int		i;
	char	*strdest;
	char	*strsrc;

	i = 0;
	if (!dst || !src)
		return (NULL);
	strdest = (char *)dst;
	strsrc = (char *)src;
	while (i < n)
	{
		strdest[i] = strsrc[i];
		i++;
	}
	return (dst);
}
