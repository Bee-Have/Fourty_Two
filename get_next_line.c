/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 12:16:18 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/22 12:02:14 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

char	*find_newline(char *str, char **line)
{
	char	*result;
	int		i;
	int		j;

	result = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	i  = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			while (str[i] != '\0')
			{
				result[j] = str[i];
				i++;
				j++;
			}
			*line = strdup_index(str, (i - j));
			result[j] = '\0';
			return (result);
		}
		i++;
	}
	*line = strdup_index(str, i);
	result[j] = '\0';
	return (result);
}

int		get_next_line(int fd, char **line)
{
	static char	*leftover = NULL;
	char		*tmp;
	int			result;

	if (!leftover)
	{
		leftover = (char *)malloc ((BUFFER_SIZE + 1) * sizeof(char));
		if (!leftover)
			return (-1);
	}
	tmp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
		return (-1);
	result = read(fd, tmp, BUFFER_SIZE);
	tmp[BUFFER_SIZE] = '\0';
	if (result == -1)
	{
		free(tmp);
		free(leftover);
		return (-1);
	}
	if (result == 0)
	{
		*line = tmp;
		leftover = NULL;
		free(leftover);
		return (0);
	}
	leftover = find_newline(tmp, line);
	free(tmp);
	return (1);
}
