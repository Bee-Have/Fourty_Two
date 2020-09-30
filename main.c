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

	result = "000000000000";
	fd = open("a.out", O_RDONLY | O_NONBLOCK);
	if (fd)
	{
		printf("fd=%d\n", fd);
		printf("result=%d\n", get_next_line(fd, &result));
		close(fd);
	}
	return (0);
}
