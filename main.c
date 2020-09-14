/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 08:38:04 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/14 15:26:19 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

int		main(void)
{
	int		i;
	char	**result;
	char	*s1 = "split  ||this|for|me|||||!|";
	char	s2 = '|';

	i = 0;	
	printf("%s		%c\n", s1, s2);
	result = ft_split(s1, s2);
	while (result[i] != NULL)
	{
		printf("%s\n", result[i]);
		i++;
	}

	return (0);
}
