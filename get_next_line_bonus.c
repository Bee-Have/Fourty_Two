/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 09:26:38 by amarini-          #+#    #+#             */
/*   Updated: 2020/10/20 09:26:42 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		find_newline(char *str, int read)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
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

int		read_fd(int fd, int *index, char **leftover, char **line)
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
	if (*index == -1)
		*line = ft_substr(*leftover, 0, ft_strlen(*leftover), 1);
	else if (*index != -1)
		*line = ft_substr(*leftover, 0, *index, 1);
	return (result);
}

void	free_leftover(char **leftover)
{
	free(*leftover);
	*leftover = NULL;
}

void	empty_leftover(char **leftover)
{
	*leftover = (char *)malloc(sizeof(char));
	if (!*leftover)
		return ;
	*leftover[0] = '\0';
}

int		get_next_line(int fd, char **line)
{
	static char		*leftover[OPEN_MAX];
	int				result;
	int				index;

	result = 1;
	index = -1;
	if (!leftover[fd])
		empty_leftover(&leftover[fd]);
	else if (leftover[fd][0] != '\0')
		index = find_newline(leftover[fd], 0);
	if (index == -1)
		result = read_fd(fd, &index, &leftover[fd], line);
	leftover[fd] = ft_substr(leftover[fd], index + 1,
		ft_strlen(leftover[fd]) - (index + 1), 0);
	if (result == -1 || (result == 0 && ft_strlen(leftover[fd]) == 0))
	{
		free_leftover(&leftover[fd]);
		return (result);
	}
	return (1);
}
