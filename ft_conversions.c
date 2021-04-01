/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 18:13:13 by amarini-          #+#    #+#             */
/*   Updated: 2021/04/01 17:32:20 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*char_to_string(char c)
{
	char	*result;

	result = (char *)malloc(2 * sizeof(char));
	if (!result)
		return (NULL);
	result[1] = '\0';
	result[0] = c;
	return (result);
}

char	*address_to_string(void *address)
{
	char						*result;
	unsigned long long int		nbr;

	if (!address)
	{
		result = str_cpy("0");
		return (result);
	}
	nbr = (unsigned long long int)address;
	result = ft_itoa_base(nbr, 16);
	return (result);
}

char	*int_to_string(unsigned int nbr)
{
	char	*result;

	result = ft_itoa(nbr);
	return (result);
}

char	*hexa_to_string(unsigned int nbr, int base)
{
	char	*result;

	result = ft_itoa_base(nbr, base);
	return (result);
}
