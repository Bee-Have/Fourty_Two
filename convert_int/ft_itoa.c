/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 14:00:04 by amarini-          #+#    #+#             */
/*   Updated: 2020/10/29 14:12:42 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_countnbr(int n, int nbr)
{
	int		count;

	if (n == 0)
		return (1);
	count = 0;
	while (nbr > 0)
	{
		nbr = nbr / 10;
		count ++;
	}
	if (n < 0)
		count++;
	return (count);
}

int		ft_check_negative(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

char	*ft_itoa(int n)
{
	int		ncount;
	int		nbr;
	char	*result;

	nbr = ft_check_negative(n);
	ncount = ft_countbr(n, nbr);
	result = (char *)malloc((ncount + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[ncount] = '\0';
	ncount--;
	while (ncount > 0 && nbr >= 10)
	{
		nbr = ft_check_negative(n) % 10;
		result[ncount] = nbr + '0';
		ncount--;
		n = n / 10;
		nbr = ft_check_negative(n);
	}
	if (ncount <= 1)
		result[ncount] = nbr + '0';
	if (n < 0)
		result[ncount - 1] = '-';
	return (result);
}