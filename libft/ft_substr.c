/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 12:36:35 by amarini-          #+#    #+#             */
/*   Updated: 2020/11/11 13:37:13 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*return_empty(void)
{
	char	*result;

	result = (char *)malloc(1 * sizeof(char));
	if (!result)
		return (NULL);
	result[0] = '\0';
	return (result);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*result;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen((char *)s) == 0 || (int)start >= ft_strlen((char *)s))
		return (return_empty());
	if (ft_strlen((char *)s) < (int)len)
		result = (char *)malloc(ft_strlen((char *)s) + 1 * sizeof(char));
	else
		result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (s[start] != '\0' && i < (int)len)
	{
		result[i] = s[start];
		i++;
		start++;
	}
	result[len] = '\0';
	return (result);
}
