/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 10:25:15 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/14 11:13:08 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*string;

	i = 0;
	string = (char *)s;
	while (string[i] != '\0')
	{
		if (string[i] == c)
			return (&string[i]);
		i++;
	}
	if (string[i] == c)
		return (&string[i]);
	return (NULL);
}
