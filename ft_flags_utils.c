/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:54:35 by amarini-          #+#    #+#             */
/*   Updated: 2021/04/06 17:52:24 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*make_extent(char fill, int length)
{
	char	*result;

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

	if ((*list)->convert == 's' && (*list)->length < ft_len((*list)->print)
		&& (*list)->len_flag == 1 && (*list)->length >= 0
		&& (*list)->neg_len == 0)
		(*list)->print = strtrim((*list)->print, (*list)->length, 0);
	else if (str_cmp((*list)->convert, NULL, "cs%") == 0
			&& (*list)->len_flag == 1 && (*list)->neg_len == 0)
	{
		if ((*list)->length == 0 && ft_len((*list)->print) <= 1
			&& (*list)->print[0] == '0')
			(*list)->print = strtrim((*list)->print, 0, 0);
		else if ((*list)->length > ft_len((*list)->print)
				&& str_cmp((*list)->convert, NULL, "pdiuxX") == 1)
		{
			if ((*list)->pad_char == ' ')
				extra = '0';
			length = (*list)->length - ft_len((*list)->print);
			extention = make_extent(extra, length);
			(*list)->print = ft_strjoin(extention, (*list)->print);
		}
	}
}

void	apply_padding(t_list **list, int *prefix_used)
{
	char	*extra;

	if ((*prefix_used) == 0 && (*list)->prefix[0] == '-')
		(*list)->padding = (*list)->padding - 1;
	(*list)->padding = calc_pad((*list)->padding, ft_len((*list)->print));
	if (ft_len((*list)->print) == 0)
		(*list)->padding += 1;
	if ((*list)->convert == 'p' && (*prefix_used) == 0
		&& (*list)->padding >= ft_len((*list)->prefix))
		(*list)->padding = (*list)->padding - ft_len((*list)->prefix);
	(*list)->length = ft_len((*list)->print) + (*list)->padding;
	extra = make_extent((*list)->pad_char, (*list)->padding);
	if ((*list)->neg_padding == 0)
		(*list)->print = ft_strjoin(extra, (*list)->print);
	else if ((*list)->neg_padding == 1)
		(*list)->print = ft_strjoin((*list)->print, extra);
	if ((*prefix_used) == 0 && ((*list)->convert == 'p' ||
		(str_cmp((*list)->convert, NULL, "di") == 1
		&& (*list)->prefix[0] == '-')))
	{
		(*list)->print = ft_strjoin((*list)->prefix, (*list)->print);
		(*prefix_used) = 1;
	}
}
