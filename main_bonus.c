/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 12:56:48 by amarini-          #+#    #+#             */
/*   Updated: 2020/10/19 12:56:51 by amarini-         ###   ########.fr       */
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
	int		i;
	int		*fd;
	char	*result;
	int		read;

	i = 0;
	read = 1;
	fd[0] = open("result.txt", O_WRONLY);
	fd[1] = open("foo.txt", O_RDONLY);
	fd[2] = open("text1.txt", O_RDONLY);
	fd[3] = open("text2.txt", O_RDONLY);
	fd[4] = open("text3.txt", O_RDONLY);
	fd[5] = open("text4.txt", O_RDONLY);
	while (read != 0 && read != -1)
		{
		while (fd[i] != '\0')
		{
			read = get_next_line(fd[1], &result);
			fill_fd(fd[i], result);
			printf("line(%d)=[%s]\n", result, fd[i]);
			free(result);
		}
		i = 1;
	}
	fd = 0;
	if (read == -1)
		printf("FAIL BITCH\n");
	while (fd[i] != '\0')
	{
		close(fd[i]);
		i++;
	}
	return (0);
}
