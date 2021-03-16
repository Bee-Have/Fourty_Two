/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converts_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 18:20:38 by amarini-          #+#    #+#             */
/*   Updated: 2021/03/15 16:12:45 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*ft_itoa_base(unsigned long long int n, int base)
{
	char				*base_info;
	int					ncount;
	unsigned long long int		n_copy;
	unsigned long long int		nbr;
	char				*result;

	base_info = "0123456789abcdef";
	n_copy = ft_check_negative((long int)n);
	ncount = ft_countnbr((long int)n, base);
	nbr = ft_check_negative(n_copy);
	result = (char *)malloc((ncount + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[ncount] = '\0';
	ncount--;
	while (ncount > 0 && nbr >= (unsigned long long int)base)
	{
		nbr = n_copy % base;
		result[ncount] = base_info[nbr];
		ncount--;
		n_copy = n_copy / base;
		nbr = n_copy;
	}
	if (ncount == 0 || ncount == 1)
		result[ncount] = base_info[nbr];
	return (result);
}

char				*ft_itoa(int n)
{
	int			ncount;
	long int	nbr;
	char		*result;

	nbr = (long int)ft_check_negative((long int)n);
	ncount = ft_countnbr(n, 10);
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
	if (ncount == 0 || ncount == 1)
	{
		result[ncount] = nbr + '0';
		ncount--;
	}
	if (n < 0)
		result[ncount] = '-';
	return (result);
}

int					ft_countnbr(long int nbr, int base)
{
	int		count;

	count = 0;
	if (nbr < 0)
		count++;
	nbr = ft_check_negative(nbr);
	while (nbr > 0)
	{
		nbr = nbr / base;
		count++;
	}
	if (count == 0)
		count++;
	return (count);
}

unsigned long long int	ft_check_negative(long int n)
{
	if (n < 0)
		n = n * -1;
	return (n);
}

char					*ft_toupper(char *str)
{
	int		i;
	
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
	return (str);
}