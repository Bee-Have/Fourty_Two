/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 07:31:14 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/01 07:33:35 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int		i;
	char	*strdest;
	char	*strsrc;

	strdest = (char *)dst;
	strsrc = (char *)src;
	i = 0;
	while (i < n)
	{
		strdest[i] = strsrc[i];
		i++;
	}
	return (dst);
}
