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
		return (0);
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

int		get_next_line(int fd, char **line)
{
	static char		*leftover = NULL;
	char			*tmp;
	int				result;
	int				index;

	index = 0;
	result = 1;
	if (fd < 0 || !line)
		return (-1);
	tmp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
		return (-1);
	while (result > 0 && index == 0)
	{
		result = read(fd, tmp, BUFFER_SIZE);
		tmp[result] = '\0';
		leftover = ft_strjoin(leftover, tmp);
		index = check_newline(leftover, result);
	}
	*line = ft_substr(leftover, 0, index);
	leftover = ft_substr(leftover, index, ft_strlen(leftover) - (index + 1));
	free(tmp);
	if (result == 0)
		return (0);
	if (result == -1)
		return (-1);
	return (1);
}
