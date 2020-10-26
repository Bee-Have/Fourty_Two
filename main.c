/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 15:28:15 by amarini-          #+#    #+#             */
/*   Updated: 2020/10/26 16:57:52 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(void)
{
	int		fd1;
	int		fd2;
	char	*line;
	int		read;
	int		wr;

	wr = 1;
	read = 1;
	fd1 = open("files/mix_marge2.txt", O_RDONLY);
	fd2 = open("files/result0.txt", O_WRONLY);
	//printf("%d\n", fd2);
	if (fd1 >= 0 && fd2)
	{
		while (read > 0&& read != -1)
		{
			read = get_next_line(fd1, &line);
			wr = write(fd2, line, ft_strlen(line));
			if (read != 0)
				wr = write(fd2, "\n", 1);
			printf("line=[%s]\n", line);
			free(line);
		}
		if (read == -1)
			printf("-1\n");
		close(fd1);
		close(fd2);
	}
	return (0);
}
