/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 11:07:40 by amarini-          #+#    #+#             */
/*   Updated: 2020/11/11 12:07:02 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flags.h"

int		calc_spaces(char *str, int padding)
{
	int		result;
	int		strlen;

	strlen = ft_strlen(str);
	if (padding < 0)
		padding *= -1;
	if (padding < strlen)
		result = strlen - padding;
	else
		result = padding - strlen;
	return (result);
}

char	*fill_pre_sufix(char *str, char fill, int spaces, int i)
{
	while (i < spaces)
	{
		str[i] = fill;
		i++;
	}
	return (str);
}