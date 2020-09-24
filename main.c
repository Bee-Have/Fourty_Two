/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 09:21:26 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/24 16:16:34 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"


int		main(void)
{
	char	*string = "      split         this for   me  !          ";
	char	sep = ' ';
	char	**result;
	int		i;
	
	i = 0;
	result = ft_split(string, sep);
	if (result == NULL)
		return (0);
	while (result[i] != NULL)
	{
		printf("%s\n", result[i]);
		i++;
	}

	return (0);
}
