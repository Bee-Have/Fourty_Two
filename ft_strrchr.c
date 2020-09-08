/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 09:11:40 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/08 16:13:57 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		occurence;
	char	*string;

	i = 0;
	occurence = 0;
	string = (char *)s;
	while (string[i] != '\0')
	{
		if (string[i] == c)
			occurence = i;
		i++;
	}
	if (string[i] == c)
		occurence = i;
	if (occurence == 0 && string[occurence] != c)
		return (NULL);
	return (&string[occurence]);
}
