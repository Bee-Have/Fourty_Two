/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 12:16:18 by amarini-          #+#    #+#             */
/*   Updated: 2020/10/09 15:12:12 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		find_newline(char *str, int read)
{
	int		i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	if (read == 0 && ft_strlen(str) == 0)
		return (i);
	return (-1);
}

int		read_fd(int fd, int *index, char **leftover)
{
	int		result;
	char	*tmp;

	result = 1;
	tmp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
		return (-1);
	while (result > 0 && *index == -1)
	{
		result = read(fd, tmp, BUFFER_SIZE);
		tmp[result] = '\0';
		*leftover = ft_strjoin(*leftover, tmp);
		*index = find_newline(*leftover, result);
	}
	free(tmp);
	return (result);
}

int		get_next_line(int fd, char **line)
{
	static char		**leftover = NULL;
	int				result;
	int				newline;
	int				index;

	newline = -1;
	index = 0;
	if (leftover && leftover[index][0] != '\0')
		newline = find_newline(leftover[index], 0);
	if (newline == -1)
		result = read_fd(fd, &newline, &leftover[index]);
	if (newline == -1)
		*line = ft_substr(leftover[index], 0, ft_strlen(leftover[index]), 1);
	else
		*line = ft_substr(leftover[index], 0, newline, 1);
	newline++;
	leftover[index] = ft_substr(leftover[index],
		newline, ft_strlen(leftover[index]) - newline, 0);
	if (result == 0 && ft_strlen(leftover[index]) == 0)
	{
		free(leftover[index]);
		return (0);
	}
	if (result == -1)
		return (-1);
	return (1);
}
