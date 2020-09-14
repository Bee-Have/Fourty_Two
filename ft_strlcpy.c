/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 10:30:02 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/14 11:22:49 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int		i;
	int					len;

	i = 0;
	len = 0;
	if (!dst && !src)
		return (len);
	while (src[len] != '\0')
		len++;
	if (dstsize <= 0)
		return (len);
	while (src[i] != '\0' && dstsize > 1)
	{
		dst[i] = src[i];
		i++;
		dstsize--;
	}
	dst[i] = '\0';
	return (len);
}
