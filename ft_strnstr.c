/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 10:44:48 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/14 11:33:37 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*string;

	i = 0;
	j = 0;
	string = (char *)haystack;
	if (ft_strlen(needle) <= 0 || needle == haystack)
		return (string);
	while (string[i] != '\0' && i < len)
	{
		while (string[i] == needle[j] && i < len && string[i] != '\0'
				&& needle[j] != '\0')
		{
			i++;
			j++;
		}
		if (needle[j] == '\0')
			return (&string[i - j]);
		j = 0;
		i++;
	}
	return (NULL);
}
