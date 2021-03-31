/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converts_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 18:20:38 by amarini-          #+#    #+#             */
/*   Updated: 2021/03/18 16:18:39 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*ft_itoa_base(unsigned long long int n, int base)
{
	char				*base_info;
	int					ncount;
	unsigned long long int		nbr;
	char				*result;

	base_info = str_cpy("0123456789abcdef");
	ncount = ft_countnbr((long int)n, base);
	nbr = ft_check_negative((long int)n);
	result = (char *)malloc((ncount + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[ncount] = '\0';
	ncount--;
	while (ncount > 0 && nbr >= (unsigned long long int)base)
	{
		nbr = ft_check_negative(n) % base;
		result[ncount] = base_info[nbr];
		ncount--;
		n = n / base;
		nbr = ft_check_negative(n);
	}
	if (ncount == 0 || ncount == 1)
		result[ncount] = base_info[nbr];
	free(base_info);
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
		result[ncount] = nbr + '0';
	if (n < 0)
		result[ncount - 1] = '-';
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