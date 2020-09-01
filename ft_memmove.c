/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 09:59:52 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/01 10:05:41 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		i;
	char	tempdst[len];
	char	*dstcopy;
	char	*srccopy;

	i = 0;
	if (!dst || !src)
		return (NULL);
	dstcopy = (char *)dst;
	srccopy = (char *)src;
	while (i < len)
	{
		tempdst[i] = srccopy[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		dstcopy[i] = tempdst[i];
		i++;
	}
	return (dstcopy);
}
