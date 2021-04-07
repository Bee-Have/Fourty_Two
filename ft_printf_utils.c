/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 18:02:45 by amarini-          #+#    #+#             */
/*   Updated: 2021/04/07 18:13:05 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		analyse_behavior(char *str, char **rest, int *i, va_list args)
{
	int		result;

	result = 0;
	(*i)++;
	ft_putstr((*rest), NULL);
	if (str_cmp(str[(*i)], NULL, "cspdiuxX%-0.*123456789") == 1)
		result += data_managment(str, i, args) + ft_len((*rest));
	else if ((*i) > 1)
		(*i)--;
	else
		(*rest)[ft_len((*rest))] = str[(*i)];
	(*rest) = fill_str((*rest), '\0', ft_len((char *)str));
	return (result);
}

int		end_rest(char *rest)
{
	int		result;

	result = 0;
	if (rest[0] != '\0')
	{
		result = ft_len(rest);
		ft_putstr(rest, NULL);
	}
	free(rest);
	return (result);
}

void	find_null_char(t_list **list)
{
	int		i;

	i = 0;
	if ((*list)->print[0] == '\0' && (*list)->convert != 'c')
		(*list)->length = 0;
	if ((*list)->null_char[0] == 1)
		while ((*list)->print[i] != '\0')
		{
			if ((*list)->print[i] == 'N')
			{
				(*list)->null_char[1] = i;
				break ;
			}
			i++;
		}
	return ;
}