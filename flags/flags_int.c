/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 16:28:39 by amarini-          #+#    #+#             */
/*   Updated: 2020/11/11 12:16:58 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flags.h"

char	*flags_int(char *str, char *flags, int padding)
{
	char	*result;
	char	fill;
	int		spaces;
	int		i;

	if (padding == 0)
		return (str);
	i = 0;
	while (flags[i] != '\0')
	{
		if (flags[i] == '0' && padding > 0)
			fill = '0';
		else if (flags[i] == ' ')
			fill = ' ';
		else if (flags[i] == '-' && padding > 0)
			padding *= -1;
		i++;
	}
	i = 0;
	spaces = calc_spaces(str, padding);
	result = (char *)malloc((space + ft_strlen(str) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[spaces + ft_strlen(str)] = '\0';
	if (padding > 0)
		result = fill_pre_sufix(str, fill, spaces, i);
	while (str[i - spaces] != '\0')
	{
		result[i] = str[i - spaces];
		i++;
	}
	if (padding < 0)
		result = fill_pre_sufix(str, fill, spaces, i - ft_strlen(str));
	return (result);
}