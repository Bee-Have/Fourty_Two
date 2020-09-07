/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 09:49:56 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/07 16:28:22 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int		i;
	int					result;
	char				*copy1;
	char				*copy2;

	i = 0;
	result = 0;
	if (!s1 || !s2)
		return (0);
	copy1 = (char *)s1;
	copy2 = (char *)s2;
	if(n <= 0)
		return (0);
	while (i <= n && copy1[i] != '\0' && copy2[i] != '\0')
	{
		printf("%d ", i);
		if (copy1[i] != copy2[i])
		{
			result = copy1[i] - copy2[i];
			return (result);
		}
		i++;
	}
	if (i <= n)
		printf("pb from N & I");
	if (copy1[i] == '\0')
		printf("pb from copy1 & end 0");
	if (copy2[i] == '\0')
		printf("pb from copy2 & end 0");
	return (0);
}
