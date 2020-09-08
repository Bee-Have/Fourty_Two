/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 09:49:56 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/08 15:55:23 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		compare(unsigned char chr1, unsigned char chr2)
{
	if (chr1 != chr2)
		return (1);
	return (0);
}

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int				i;
	unsigned char				*copy1;
	unsigned char				*copy2;

	i = 0;
	if (!s1 || !s2)
		return (0);
	copy1 = (unsigned char *)s1;
	copy2 = (unsigned char *)s2;
	if (n <= 0)
		return (0);
	while (i < n && copy1[i] != '\0' && copy2[i] != '\0')
	{
		if ((unsigned char)compare(copy1[i], (unsigned char)copy2[i]) == 1)
			return (copy1[i] - copy2[i]);
		i++;
	}
	if ((copy1[i] == '\0' || copy2[i] == '\0') &&
			(compare(copy1[i], copy2[i]) == 1))
		return (copy1[i] - copy2[i]);
	return (0);
}
