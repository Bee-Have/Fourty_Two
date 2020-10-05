/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 11:03:00 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/22 11:19:40 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char	*strdup_index(char *str, int index)
{
	char	*result;
	int		i;

	i = 0;
	result = (char *)malloc((index + 1) * sizeof(char));
	while (i < index)
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*empty_string(char *str, int size)
{
	int		i;

	str = (char *)malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i <= size)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}

int		ft_strlen(char str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*join_line(char *s1, char *s2)
{
	int		i;
	int		j;
	int		length;
	char	*result;

	i = 0;
	j = 0;
	length = ft_strlen(s1) + ft_strlen(s2);
	result = (char *)malloc((length + 1) * sizeof(char));
	if (!result)
	result[length] = '\0';
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	while (i < length)
	{
		result[i] = s2[j];
		i++;
		j++;
	}
	return (result);
}
