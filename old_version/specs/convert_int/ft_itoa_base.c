/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 14:15:33 by amarini-          #+#    #+#             */
/*   Updated: 2020/11/13 21:16:48 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert_int.h"

char	*ft_itoa_base(int n, int base)
{
	char	*base_info;
	int		ncount;
	int		nbr;
	char	*result;

	base_info = "0123456789abcdef";
	nbr = ft_check_negative(n);
	ncount = ft_countnbr(nbr, base);
	result = (char *)malloc((ncount + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[ncount] = '\0';
	ncount--;
	while (ncount > 0 && nbr >= base)
	{
		nbr = ft_check_negative(n) % base;
		result[ncount] = base_info[nbr];
		ncount--;
		n = n / base;
		nbr = ft_check_negative(n);
	}
	if (ncount <= 1)
		result[ncount] = base_info[nbr];
	if (n < 0)
		result[ncount - 1] = '-';
	return (result);
}