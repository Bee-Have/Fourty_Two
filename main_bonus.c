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
	printf("res=[%s]\n", str);
	i = write(fd, str, ft_strlen(str));
	i = write(fd, "\n", 1);
}

int		main(void)
{
	int		i;
	int		*fd;
	int		*res;
	char	*result;
	int		read[6];
	int		end;

	i = 0;
	end = 0;
	while (i < 5)
	{
		read[i] = 1;
		i++;
	}
	read[5] = -5;
	i = 0;
	res = (int *)malloc(6 * sizeof(int));
	fd = (int *)malloc(6 * sizeof(int));
	if (!fd || !res)
		return (0);
	fd[0] = open("foo.txt", O_RDONLY);
	fd[1] = open("text1.txt", O_RDONLY);
	fd[2] = open("text2.txt", O_RDONLY);
	fd[3] = open("text3.txt", O_RDONLY);
	fd[4] = open("text4.txt", O_RDONLY);
	fd[5] = -1;
	res[0] = open("result0.txt", O_WRONLY);
	res[1] = open("result1.txt", O_WRONLY);
	res[2] = open("result2.txt", O_WRONLY);
	res[3] = open("result3.txt", O_WRONLY);
	res[4] = open("result4.txt", O_WRONLY);
	res[5] = -1;
	while (read[0] == 1 || read[1] == 1 || read[2] == 1 || read[3] == 1 || read[4] == 1)
	{
		while (i < 5)
		{
			if (read[i] > 0)
			{
				read[i] = get_next_line(fd[i], &result);
				fill_fd(res[i], result);
				printf("fd{%d}->[%d]=[%s]\n", fd[i], read[i], result);
				//system ("leaks a.out | grep 'leaked'");
				free(result);
				result = NULL;
			}
			i++;
		}
		i = 0;
	}
	i = 0;
	while (i >= 5)
	{
		close(res[i]);
		close(fd[i]);
		i++;
	}
	return (0);
}
