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
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	if (read == 0)
		return (i);
	return (0);
}

int		read_fd(int fd, int *index, char **leftover)
{
	int		result;
	char	*tmp;

	result = 1;
	tmp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	while (result > 0 && *index == 0)
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
	static char		*leftover = NULL;
	int				result;
	int				index;

	index = 0;
	result = 0;
	if (leftover)
		index = find_newline(leftover, 1);
	if (index == 0)
		result = read_fd(fd, &index, &leftover);
	/*while (result > 0 && index == 0)
		result = read_fd(fd, &index, &leftover);*/
	*line = ft_substr(leftover, 0, index, 1);
	index++;
	leftover = ft_substr(leftover, index, ft_strlen(leftover) - index, 0);
	if (result == 0 && index == 0)
	{
		free(leftover);
		return (0);
	}
	if (result == -1)
		return (-1);
	return (1);
}
