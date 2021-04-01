/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 21:45:17 by amarini-          #+#    #+#             */
/*   Updated: 2021/04/01 17:30:59 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_write(char c)
{
	write(0, &c, 1);
	return ;
}

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return ;
	while (str[i] != '\0')
	{
		ft_write(str[i]);
		i++;
	}
	return ;
}
