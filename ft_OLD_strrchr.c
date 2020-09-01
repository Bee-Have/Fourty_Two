/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 07:39:02 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/01 08:31:16 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		occurrence;
	char	*string;

	i = 0;
	occurrence = 0;
	string = (char *)s;
	while (string[i] != '\0')
	{
		if (string[i] == c)
			occurrence = i;
		i++;
	}
	if (occurrence == 0 && string[occurrence] != c)
		return (NULL);
	return (&string[occurrence]);
}
