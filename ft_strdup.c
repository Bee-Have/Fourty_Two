/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 07:41:27 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/01 07:41:29 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*cp;

	i = 0;
	if (!s1)
		return (NULL);
	cp = (char *)malloc(sizeof(s1));
	if (!cp)
		return (NULL);
	while (s1[i] != '\0')
	{
		cp[i] = s1[i];
		i++;
	}
	return (cp);
}
