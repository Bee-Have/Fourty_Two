/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 15:28:15 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/30 15:28:25 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"


int		main(void)
{
	int		fd;
	char	*result;
	int		this;

	this = 1;
	fd = open("foo.txt", O_RDONLY | O_NONBLOCK);
	if (fd)
	{
		printf("fd=%d\n", fd);
		while (this != 0 && this != -1)
		{
			this = get_next_line(fd, &result);
			printf("[%s]\n", result);
		}
		if (this == -1)
			printf("-1\n");
		printf("%d\n", this);
		close(fd);
	}
	return (0);
}
