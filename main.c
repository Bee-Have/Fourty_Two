/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 08:38:04 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/09 16:38:06 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

int		main(void)
{
	char	**result;
	char	*str1;
	char	sep = ' ';
	int		i;
	int		j;

	i = 0;

	result = ft_split(str1, sep);
	while (result[i] != NULL)
	{
		j = 0;
		while (result[i][j] != '\0')
		{
			printf("%c", result[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}

	return (0);
}
