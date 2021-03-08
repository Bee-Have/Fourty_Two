/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:07:24 by amarini-          #+#    #+#             */
/*   Updated: 2021/02/18 18:55:06 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*str_trim(char *str, int length, int start)
{
	char	*result;
	int		i;

	i = 0;
	if (length == 0)
		result = (char *)malloc(sizeof(char));
	else
		result = (char *)malloc((length + 1) * sizeof(char));
	result[length] = '\0';
	while (i < length)
	{
		result[i] = str[start];
		i++;
		start++;
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

void	register_negative_padding(char *str, int *i, t_list **list, int *nbr)
{
	if (str[(*i)] == '-')
	{
		if ((*list)->len_flag == 0)
		{
			(*list)->neg_padding = 1;
			(*list)->pad_char = ' ';
		}
		else
		{
			(*list)->neg_len = 1;
			(*list)->problem = 1;
		}
		(*i)++;
	}
	else if ((*list)->padding < 0 || (*list)->length < 0)
	{
		if ((*list)->len_flag == 0)
		{
			(*list)->neg_padding = 1;
			(*list)->pad_char = ' ';
		}
		else
			(*list)->neg_len = 1;
		(*list)->padding = (*list)->padding * -1;
	}
	else if ((*nbr) < 0)
	{
		if ((*list)->len_flag == 0)
		{
			(*list)->neg_padding = 1;
			(*list)->pad_char = ' ';
		}
		else
			(*list)->neg_len = 1;
		(*nbr) = (*nbr) * -1;
	}
	return ;
}

int		ft_str_cmp(char c, char *str, char *cmp)
{
	int		i;

	if (!c && !str)
		return (1);
	i = 0;
	if (c && !str)
	{
		while (cmp[i] != '\0')
		{
			if (cmp[i] == c)
				return (1);
			i++;
		}
	}
	else
	{
		while (str[i] != '\0' && cmp[i] != '\0')
		{
			if (str[i] != cmp[i])
				return (1);
			i++;
		}
		
	}
	return (0);
}