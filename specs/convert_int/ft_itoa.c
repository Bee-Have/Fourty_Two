/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 14:00:04 by amarini-          #+#    #+#             */
/*   Updated: 2020/10/29 16:06:29 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert_int.h"

char	*ft_itoa(int n)
{
	int		ncount;
	int		nbr;
	char	*result;

	nbr = ft_check_negative(n);
	ncount = ft_countnbr(n, nbr, 10);
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