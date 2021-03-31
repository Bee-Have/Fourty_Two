/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:54:35 by amarini-          #+#    #+#             */
/*   Updated: 2021/03/29 19:11:58 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*make_extent(char fill, int length, char convertion)
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

void	length_managment(t_list **list, char extra)
{
	char	*extention;
	int		length;

	if ((*list)->convert == 's' && (*list)->length < ft_strlen((*list)->print)
		&& (*list)->len_flag == 1 && (*list)->length >= 0)
		(*list)->print = str_trim((*list)->print, (*list)->length, 0);
	else if ((*list)->convert != 'c' && (*list)->convert != 's'
			&& (*list)->len_flag == 1)
	{
		if ((*list)->length == 0 && ft_strlen((*list)->print) <= 1
			&& (*list)->print[0] == '0')
			(*list)->print = str_trim((*list)->print, 0, 0);
		else if ((*list)->length > ft_strlen((*list)->print))
		{
			if ((*list)->pad_char == ' ')
				extra = '0';
			length = (*list)->length - ft_strlen((*list)->print);
			extention = make_extent(extra, length, (*list)->convert);
			(*list)->print = ft_strjoin(extention, (*list)->print);
		}
	}
}

void	apply_padding(t_list **list, int *prefix_used)
{
	char	*extend;

	if ((*prefix_used) == 0 && (*list)->prefix[0] == '-')
			(*list)->padding = (*list)->padding - 1;
	(*list)->padding = calc_pad((*list)->padding, ft_strlen((*list)->print));
	(*list)->length = ft_strlen((*list)->print) + (*list)->padding;
	extend =make_extent((*list)->pad_char, (*list)->padding, (*list)->convert);
	if ((*list)->neg_padding == 0)
		(*list)->print = ft_strjoin(extend, (*list)->print);
	else if ((*list)->neg_padding == 1)
		(*list)->print = ft_strjoin((*list)->print, extend);
	if ((*prefix_used) == 0 && ((*list)->convert == 'p' ||
		(str_cmp((*list)->convert, NULL, "di") == 1 
		&& (*list)->prefix[0] == '-')))
	{
		(*list)->print = ft_strjoin((*list)->prefix, (*list)->print);
		(*prefix_used) = 1;
	}
}