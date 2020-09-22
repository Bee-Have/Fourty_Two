/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 11:03:00 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/22 11:19:40 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char	*check_str(char *str)
{
	int		i;
	int		size;
	char	*result;

	i = 0;
	size = 0;
	while (str[size] != '\0')
	{
		if (str[size] == '\n')
		{
			result = (char *)malloc((size + 1) * sizeof(char));
			while (i < size)
			{
				result[i] = str[i];
				i++;
			}
			result[i] = '\0';
			return (result);
		}
		size++;
	}
	return (str);
}
