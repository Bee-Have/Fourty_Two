/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 10:41:17 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/08 16:00:10 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int		i;
	unsigned char		a;
	unsigned char		b;

	i = 0;
	a = 'a';
	b = 'a';
	if (!s1 || !s2)
		return (0);
	while (i < n)
	{
		a = (unsigned char)s1[i];
		b = (unsigned char)s2[i];
		if (a != b)
			return (a - b);
		i++;
	}
	return (0);
}
