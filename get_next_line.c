/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 12:16:18 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/22 10:37:14 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

char	*check_str(char *str)
{
	int		i;
	int		size;
	char	*result;

	i = 0;
	size = 0;
	while (str[size] != '\0')
	{
		if (str[size] == '\n')
		{
			result = (char *)malloc((size + 1) * sizeof(char));
			while (i < size)
			{
				result[i] = str[i];
				i++;
			}
			result[i] = '\0';
			return (result);
		}
		size++;
	}
	return (str);
}

int		get_next_line(int fd, char **line)
{
	static char	*buffer;
	int			current;

	printf("BUFFER_SIZE=%d\n", BUFFER_SIZE);
	current = 0;
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (-1);
	current = read(fd, buffer, BUFFER_SIZE);
	buffer[BUFFER_SIZE] = '\0';
	*line = check_str(buffer);
	printf("%s\n", *line);
	if (current < 0)
		return (-1);
	if (current > 0)
		return (1);
	return (0);
}

int		main(void)
{
	int		fd;
	//int		other;
	char	*result;

	result = "000000000000";
	fd = open("/dev/pts/2", O_RDONLY | O_NONBLOCK);
	if (fd)
	{
		printf("fd=%d\n", fd);
		//other = get_next_line(0, &result);
		printf("result=%d\n", get_next_line(fd, &result));
		close(fd);
	}
	return (0);
}
