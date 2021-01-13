/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 18:13:13 by amarini-          #+#    #+#             */
/*   Updated: 2021/01/13 13:02:08 by amarini-         ###   ########.fr       */
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

char	*address_to_string(unsigned int nbr)
{
	char	*result;

	result = ft_itoa_base(nbr, 16);
	result = ft_strjoin("0x", result);
	return (result);
}

char	*int_to_string(unsigned int nbr)
{
	char	*result;

	result = ft_itoa(nbr);
	return(result);
}

char	*hexa_to_string(unsigned int nbr)
{
	char	*result;

	result = ft_itoa_base(nbr, 16);
	return (result);
}