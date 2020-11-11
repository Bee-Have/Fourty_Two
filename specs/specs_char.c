/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specs_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 17:43:05 by amarini-          #+#    #+#             */
/*   Updated: 2020/11/11 12:46:35 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifications.h"

char	*spec_c(va_list args)
{
	char	*result;

	result = (char *)malloc(2 * sizeof(char));
	if (!result)
		return (NULL);
	result[1] = '\0';
	result[0] = va_arg(args, int);
	return (result);
}

char	*spec_s(va_list args)
{
	char	*tmp;
	char	*result;
	int		i;

	tmp = va_arg(args, char*);
	i = 0;
	result = (char *)malloc((ft_strlen(tmp) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[ft_strlen(tmp)] = '\0';
	while (tmp[i] != '\0')
	{
		result[i] = tmp[i];
		i++;
	}
	return (result);
}

char	*spec_percentage(va_list args)
{
	char	*result;

	args = args;
	result = (char *)malloc(2 * sizeof(char));
	if (!result)
		return (NULL);
	result[1] = '\0';
	result[0] = '%';
	return (result);
}