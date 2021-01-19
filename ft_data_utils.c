/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:07:24 by amarini-          #+#    #+#             */
/*   Updated: 2021/01/18 16:05:45 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*str_trim(char *str, int length)
{
	char	*result;
	int		i;

	i = 0;
	result = (char *)malloc((length + 1) * sizeof(char));
	result[length] = '\0';
	while (i < length)
	{
		result[i] = str[i];
		i++;
	}
	free(str);
	return (result);
}

char	*make_extention(char fill, int length, char convertion)
{
	char	*result;
	
	if (fill == '0' && (convertion == 'c' || convertion == 's'))
		fill = ' ';
	result = (char *)malloc((length + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result = fill_str(result, fill, length);
	return (result);
}

int		register_padding_flags(char *str, int *i, t_list **list)
{
	int		result;

	result = 0;
	(*i)++;
	if (str[(*i)] == '-')
	{
		(*list)->neg_padding = 1;
		(*list)->pad_char = ' ';
		(*i)++;
	}
	while (str[(*i)] != '\0' && str[(*i)] >= '0' && str[(*i)] <= '9')
	{
		result = (result * 10) + (str[(*i)] - '0');
		(*i)++;
	}
	(*i)--;
	return (result);
}

int		calculate_padding(int padding, int length)
{
	int		result;

	result = 0;
	if (padding > length)
		result = padding - length;
	else
		result = 0;
	return (result);
}