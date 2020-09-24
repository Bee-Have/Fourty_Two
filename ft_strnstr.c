/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 10:44:48 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/24 16:04:57 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!haystack || !needle)
		return (NULL);
	if (ft_strlen(needle) <= 0 || needle == haystack)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		while (i < len && haystack[i] == needle[j] && haystack[i] != '\0'
				&& needle[j] != '\0')
		{
			i++;
			j++;
		}
		if (needle[j] == '\0')
			return ((char *)&haystack[i - j]);
		i++;
	}
	return (NULL);
}
