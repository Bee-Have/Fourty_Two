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

int		find_newline(char *str)
{
	int		i;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

char	*fill_str(int index, char *src, char *dst, char *leftover)
{
	int		i;
	int		ibis;
	int		j;

	i = 0;
	ibis = 0;
	j = 0;
	while (dst[i] != '\0')
		i++;
	while (ibis < index)
	{
		dst[i] = src[ibis];
		i++;
		ibis++;
	}
	while (src[i] != '\0')
	{
		leftover[j] = src[ibis];
		ibis++;
		j++;
	}
	leftover[j] = '\0';
	return (dst);
}

int		get_next_line(int fd, char **line)
{
	static char		*leftover = NULL;
	char			*tmp;
	int				result;
	int				index;

	result = 1;
	index = 0;
	if (!leftover)
	{
		leftover = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		result = 1;
	}
	else
	{
		index = find_newline(leftover);
		if (index > 0)
		{
			//put leftover until '\n' in **line
			// leftover = leftover after '\n'
			*line = fill_str(index, leftover, *line, leftover);
			return (1);
		}
		while (result > 0)
		{
			//read fd
			result = read(fd, tmp, BUFFER_SIZE);
			index = find_newline(tmp);
			if (index > 0)
			{
				//**line = strjoin(leftover, tmp(until '\n')
				//leftover = tmp after '\n'
				*line = fill_str(ft_strlen(leftover), leftover, *line, leftover);
				*line = fill_str(index, tmp, *line, leftover);
				return (1);
			}
		}
	}
	while (result > 0)
	{
		result = read(fd, tmp, BUFFER_SIZE);
		index = find_newline(tmp);
		if (index > 0)
		{
			//**line = tmp until '\n'
			//leftover = tmp after '\n'
			*line = fill_str(index, tmp, *line, leftover);
			return (1);
		}
		else
			//leftover = tmp
	}
	if (result = 0
	{
		//if (leftover[0] != '\0')
			//**line = leftover
		free(tmp);
		free(leftover);
		return (0);
	}
	if (/*read = -1*/)
	{
		free(leftover);
		free(tmp);
		return (-1);
	}
	return (-1);
}
