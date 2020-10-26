/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 12:56:48 by amarini-          #+#    #+#             */
/*   Updated: 2020/10/26 17:32:49 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(void)
{
	int		i;
	int		*fd;
	int		*res;
	char	*result;
	int		read[23];
	int		end;
	int		wr;

	i = 0;
	wr = 1;
	end = 0;
	while (i < 21)
	{
		read[i] = 1;
		i++;
	}
	read[21] = -5;
	i = 0;
	if (!(fd = (int *)malloc(23 * sizeof(int))) || !(res = (int *)malloc(23 * sizeof(int))))
		return (0);
	fd[0] = open("files/1_newline.txt", O_RDONLY);
	fd[1] = open("files/4_newlines.txt", O_RDONLY);
	fd[2] = open("files/41_char.txt", O_RDONLY);
	fd[3] = open("files/42_char.txt", O_RDONLY);
	fd[4] = open("files/43_char.txt", O_RDONLY);
	fd[5] = open("files/alphabet.txt", O_RDONLY);
	fd[6] = open("files/empty_file.txt", O_RDONLY);
	fd[7] = open("files/empty_lines.txt", O_RDONLY);
	fd[8] = open("files/foo.txt", O_RDONLY);
	fd[9] = open("files/half_marge_bottom.txt", O_RDONLY);
	fd[10] = open("files/half_marge_top.txt", O_RDONLY);
	fd[11] = open("files/huge_alphabet.txt", O_RDONLY);
	fd[12] = open("files/huge_file.txt", O_RDONLY);
	fd[13] = open("files/huge_line.txt", O_RDONLY);
	fd[14] = open("files/huge_lines.txt", O_RDONLY);
	fd[15] = open("files/huge_lines2.txt", O_RDONLY);
	fd[16] = open("files/mix_marge1.txt", O_RDONLY);
	fd[17] = open("files/mix_marge2.txt", O_RDONLY);
	fd[18] = open("files/text1.txt", O_RDONLY);
	fd[19] = open("files/text2.txt", O_RDONLY);
	fd[20] = open("files/text3.txt", O_RDONLY);
	fd[21] = open("files/text4.txt", O_RDONLY);
	fd[22] = -1;
	res[0] = open("files/result0.txt", O_WRONLY);
	res[1] = open("files/result1.txt", O_WRONLY);
	res[2] = open("files/result2.txt", O_WRONLY);
	res[3] = open("files/result3.txt", O_WRONLY);
	res[4] = open("files/result4.txt", O_WRONLY);
	res[5] = open("files/result5.txt", O_WRONLY);
	res[6] = open("files/result6.txt", O_WRONLY);
	res[7] = open("files/result7.txt", O_WRONLY);
	res[8] = open("files/result8.txt", O_WRONLY);
	res[9] = open("files/result9.txt", O_WRONLY);
	res[10] = open("files/result10.txt", O_WRONLY);
	res[11] = open("files/result11.txt", O_WRONLY);
	res[12] = open("files/result12.txt", O_WRONLY);
	res[13] = open("files/result13.txt", O_WRONLY);
	res[14] = open("files/result14.txt", O_WRONLY);
	res[15] = open("files/result15.txt", O_WRONLY);
	res[16] = open("files/result16.txt", O_WRONLY);
	res[17] = open("files/result17.txt", O_WRONLY);
	res[18] = open("files/result18.txt", O_WRONLY);
	res[19] = open("files/result19.txt", O_WRONLY);
	res[20] = open("files/result20.txt", O_WRONLY);
	res[21] = open("files/result21.txt", O_WRONLY);
	res[22] = -1;
	while (read[0] == 1 || read[1] == 1 || read[2] == 1
		|| read[3] == 1 || read[4] == 1 || read[5] == 1 || read[6] == 1
		|| read[7] == 1 || read[8] == 1 || read[9] == 1 || read[10] == 1
		|| read[11] == 1 || read[12] == 1 || read[13] == 1 || read[14] == 1
		|| read[15] == 1 || read[16] == 1 || read[17] == 1 || read[18] == 1
		|| read[19] == 1 || read[20] == 1 || read[21] == 1)
	{
		while (i < 22)
		{
			if (read[i] > 0)
			{
				read[i] = get_next_line(fd[i], &result);
				wr = write(res[i], result, ft_strlen(result));
				if (read[i] != 0)
					wr = write(res[i], "\n", 1);
				printf("fd{%d}->[%d]=[%s]\n", fd[i], read[i], result);
				free(result);
				result = NULL;
			}
			i++;
		}
		i = 0;
	}
	i = 0;
	while (i >= 22)
	{
		close(res[i]);
		close(fd[i]);
		i++;
	}
	return (0);
}
