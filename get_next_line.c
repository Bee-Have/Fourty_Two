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

int		new_line(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*fill_line_leftover(char *str, char **line)
{
	char	*result;
	int		i;
	int		j;

	result = NULL;
	result = empty_string(result, BUFFER_SIZE);
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			i++;
			while (str[i] != '\0')
			{
				result[j] = str[i];
				i++;
				j++;
			}
			*line = strdup_index(str, (i - j));
			return (result);
		}
		i++;
	}
	*line = strdup_index(str, i);
	return (result);
}

int		get_next_line(int fd, char **line)
{
	static char	*leftover = NULL;
	char		*tmp;
	int			result;

	tmp = NULL;
	if (!leftover)
		leftover = empty_string(leftover, BUFFER_SIZE);
	if (leftover[0] != '\0')
	{
		leftover = fill_line(leftover, line);
		return (1);
	}
	tmp = empty_string(tmp, BUFFER_SIZE);
	result = read(fd, tmp, BUFFER_SIZE);
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
	leftover = fill_line(tmp, line);
	free(tmp);
	return (1);
}
