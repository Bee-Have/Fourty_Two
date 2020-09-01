/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 07:31:57 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/01 07:34:02 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		i;
	char	tempdst[len];
	char	*cpdst;
	char	*cpsrc;

	i = 0;
	cpdst = (char *)dst;
	cpsrc = (char *)src;
	while (i < len)
	{
		tempdst[i] = cpsrc[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		cpdst[i] = tempdst[i];
		i++;
	}
	return (dst);
}
