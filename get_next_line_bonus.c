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

int		read_fd(int fd, int *index, t_list **leftover)
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
		(*leftover)->line = ft_strjoin((*leftover)->line, tmp);
		*index = find_newline((*leftover)->line, result);
	}
	free(tmp);
	return (result);
}

void	setup_leftover(t_list **leftover, int fd)
{
	t_list	*head;

	if (!leftover)
	{
		head = NULL;
		head = (t_list *)malloc(sizeof(t_list));
		if (!head)
			return /*(NULL)*/;
		head->file = fd;
		head->next = NULL;
		return /*(head->line)*/;
	}
	head = *leftover;
	while (head->next != NULL)
	{
		if (head->file == fd)
			return /*(head->line)*/;
		head = head->next;
	}
	head = (t_list *)malloc(sizeof(t_list));
	if (!head)
		return /*(NULL)*/;//a changer
	head->file = fd;
	head->next = NULL;
	return /*(head->line)*/;
}

int		get_next_line(int fd, char **line)
{
	static t_list		*leftover = NULL;
	int					result;
	int					newline;

	result = 1;
	newline = -1;
	setup_leftover(&leftover, fd);
	if (leftover && leftover->line != '\0')
		newline = find_newline(leftover->line, 0);
	if (newline == -1)
		result = read_fd(fd, &newline, &leftover);
	if (newline == -1)
		*line = ft_substr(leftover->line, 0, ft_strlen(leftover->line), 1);
	else
		*line = ft_substr(leftover->line, 0, newline, 1);
	newline++;
	leftover->line = ft_substr(leftover->line,
		newline, ft_strlen(leftover->line) - newline, 0);
	if (result == 0 && ft_strlen(leftover->line) == 0)
	{
		free(leftover);
		return (0);
	}
	if (result == -1)
		return (-1);
	return (1);
}
