/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 07:39:51 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/11 11:17:36 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	maxlen;
	char			*dstcopy;
	char			*srccopy;

	i = 0;
	j = 0;
	maxlen = 0;
	dstcopy = (char *)dst;
	srccopy = (char *)src;
	i = ft_strlen(dstcopy);
	maxlen = ft_strlen(dstcopy) + ft_strlen(srccopy);
	if (i > dstsize)
		return (ft_strlen(srccopy) + dstsize);
	while (i < (dstsize - 1) && srccopy[j] != '\0')
	{
		dstcopy[i] = srccopy[j];
		i++;
		j++;
	}
	dstcopy[i] = '\0';
	return (maxlen);
}
