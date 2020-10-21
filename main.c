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

#include "get_next_line.h"

void	fill_fd(int fd, char *str)
{
	int		i;

	i = 1;
	i = write(fd, str, ft_strlen(str));
	i = write(fd, "\n", 1);
}

int		main(void)
{
	int		fd1;
	int		fd2;
	char	*result;
	int		read;

	read = 1;
	fd1 = 0;//open("foo.txt", O_RDONLY);
	fd2 = open("result.txt", O_WRONLY);
	if (fd1 >= 0 && fd2)
	{
		while (read != 0 && read != -1)
		{
			read = get_next_line(fd1, &result);
			fill_fd(fd2, result);
			printf("line=[%s]\n", result);
			//printf("result=%d\n", read);
			free(result);
		}
		if (read == -1)
			printf("-1\n");
		close(fd1);
		close(fd2);
	}
	return (0);
}
