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

#include "get_next_line.h"

int		check_newline(char *str, int read)
{
	int		i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			if (i > 1)
				return (i);
			else
				return (1);
		}
		i++;
	}
	if (read == 0)
		return (i);
	return (0);
}

int		read_fd(int fd, char **leftover, int *index, int *result)
{
	char	*tmp;

	tmp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
		return (-1);
	*result = read(fd, tmp, BUFFER_SIZE);
	tmp[*result] = '\0';
	*leftover = ft_strjoin(*leftover, tmp);
	*index = check_newline(*leftover, *result);
	free(tmp);
	return (*result);
}

int		get_next_line(int fd, char **line)
{
	static char		*leftover = NULL;
	int				result;
	int				index;

	index = 0;
	result = 1;
	if (fd < 0 || !line)
		return (-1);
	if (leftover)
		index = check_newline(leftover, result);
	while (result > 0 && index == 0)
		read_fd(fd, &leftover, &index, &result);
	*line = ft_substr(leftover, 0, index);
	leftover = ft_substr(leftover, index, ft_strlen(leftover) - (index + 1));
	if (result == 0 && leftover[0] == '\0')
		return (0);
	if (result == -1)
		return (-1);
	return (1);
}
