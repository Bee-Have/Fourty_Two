/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 14:05:19 by amarini-          #+#    #+#             */
/*   Updated: 2020/11/13 14:09:19 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flags.h"

char	*flags_char(char *str, char *flags, int padding)
{
	char	*result;
	int		i;
	int		spaces;
	
	if (padding == 0)
		return (str);
	i = 0;
	while (flags[i] != '\0')
	{
		if (flags[i] == '-' && padding > 0)
			padding *= -1;
		if(flags[i] == '0' || flags[i] == '.')
			return (str);
		i++;
	}
	i = 0;
	spaces = calc_spaces(str, padding);
	result = (char *)malloc((spaces + ft_strlen(str) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[spaces + ft_strlen(str)] = '\0';
	if (padding > 0)
		result = fill_pre_sufix(str, ' ', spaces, i);
	while (str[i - spaces] != '\0')
	{
		result[i] = str[i - spaces];
		i++;
	}
	if (padding < 0)
		result = fill_pre_sufix(str, ' ', spaces, i - ft_strlen(str));
	free(str);
	return (result);
}