/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 09:49:56 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/01 09:54:24 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int		i;
	int		result;
	char	*copy1;
	char	*copy2;

	i = 0;
	result = 0;
	if (!s1 || !s2)
		return (0);
	copy1 = (char *)s1;
	copy2 = (char *)s2;
	if (n <= 0)
		return (0);
	while (i < n && copy[1] != '\0' && copy2[i] != '\0')
	{
		if (copy1[i] != copy2[i])
		{
			result = copy1[i] - copy2[i];
			return (result);
		}
		i++;
	}
	return (0);
}
