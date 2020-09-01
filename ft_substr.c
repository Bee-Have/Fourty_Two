/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 07:41:45 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/01 07:41:47 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*cp;

	i = 0;
	cp = (char *)malloc(len);
	if (!cp)
		return (NULL);
	while (s[start] != '\0')
	{
		cp[i] = s[start];
		i++;
		start++;
	}
	cp[i++] = '\0';
	return (cp);
}
