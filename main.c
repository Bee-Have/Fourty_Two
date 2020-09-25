/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 09:21:26 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/25 11:44:05 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"


int		main(void)
{
	char	*string = "   lorem         ipsum   dolor    sit      amet,    consectetur    adipiscing       elit.    Sed    non    risus. Suspendisse            "; 
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
