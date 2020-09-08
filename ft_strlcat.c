/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 07:39:51 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/08 13:02:35 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int			calc_len(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

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
	i = calc_len(dstcopy);
	if (i >= dstsize)
		return (calc_len(srccopy));
	maxlen = calc_len(dstcopy) + calc_len(srccopy);
	while (i < (dstsize - 1) && srccopy[j] != '\0')
	{
		dstcopy[i] = srccopy[j];
		i++;
		j++;
	}
	dstcopy[i] = '\0';
	return (maxlen);
}
