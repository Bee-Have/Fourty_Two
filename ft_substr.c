/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 07:41:45 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/14 15:59:33 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*result;

	i = 0;
	if (!s || (int)len < 0)
		return (NULL);
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	if ((int)start >= ft_strlen(s))
		return (result);
	while (s[start] != '\0' && i < (int)len)
	{
		result[i] = s[start];
		i++;
		start++;
	}
	result[i++] = '\0';
	return (result);
}
