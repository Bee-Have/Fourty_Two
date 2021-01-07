/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 15:33:52 by amarini-          #+#    #+#             */
/*   Updated: 2020/11/13 21:16:29 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert_int.h"

int		ft_countnbr(int nbr, int base)
{
	int		count;

	count = 0;
	while (nbr > 0)
	{
		nbr = nbr / base;
		count++;
	}
	if (nbr < 0)
		count++;
	return (count);
}

int		ft_check_negative(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}