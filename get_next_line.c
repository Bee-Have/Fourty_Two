/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 12:16:18 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/21 16:51:43 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

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
	*line[BUFFER_SIZE] = '\0';
	*line = buffer;
	//printf("%s\n", *line);
	if (current < 0)
		return (-1);
	if (current > 0)
		return (1);
	return (0);
}

int		main(void)
{
	int		fd;
	int		wrt;
	char	*result;

	result = "000000000000";
	fd = open("foo.txt", O_RDWR | O_CREAT);
	printf("fd=%d\n", fd);
	wrt = write(fd, "hello there\n", BUFFER_SIZE);
	printf("result=%d\n", get_next_line(fd, &result));
	printf("wrote %d number of characters\n", wrt);
	close(fd);
	return (0);
}
