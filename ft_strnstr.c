/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 10:44:48 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/08 16:06:39 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*string;

	i = 0;
	j = 0;
	if (!haystack)
		return (NULL);
	string = (char *)haystack;
	if (!needle)
		return (string);
	while (string[i] != '\0' && i < len)
	{
		while (string[i] == needle[j] && i < len)
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
