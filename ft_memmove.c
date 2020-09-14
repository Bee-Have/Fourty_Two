/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 09:59:52 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/14 10:59:11 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*dstcopy;
	char	*srccopy;

	i = 0;
	dstcopy = (char *)dst;
	srccopy = (char *)src;
	if ((!dst && !src) || src == dst)
		return (srccopy);
	if (dst < src)
		while (i < len)
		{
			dstcopy[i] = srccopy[i];
			i++;
		}
	else if (dst > src)
		while (len > 0)
		{
			len--;
			dstcopy[len] = srccopy[len];
		}
	return (dstcopy);
}
