/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 07:39:34 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/01 07:39:36 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int		i;

	i = 0;
	if (dstsize < 0)
		return (0);
	while (src[i] != '\0' && dstsize > 1)
	{
		dst[i] = src[i];
		i++;
		dstsize--;
	}
	dst[i] = '\0';
	return (i);
}
