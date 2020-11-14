/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specs_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 17:35:43 by amarini-          #+#    #+#             */
/*   Updated: 2020/11/13 21:12:43 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifications.h"

char	*spec_p(va_list args)
{
	//this behavior might not be working yet
	char	*result;
	int		nbr;

	nbr = va_arg(args, int);
	result = ft_itoa_base(nbr, 16);
	result = ft_strjoin("x0", result);
	return (result);
}

char	*spec_di(va_list args)
{
	char	*result;
	
	int		nbr;

	nbr = va_arg(args, int);
	result = ft_itoa(nbr);
	return (result);
}

char	*spec_u(va_list args)
{
	char			*result;
	unsigned int	nbr;

	nbr = va_arg(args, unsigned int);
	result = ft_itoa(nbr);
	return (result);
}

char	*spec_xX(va_list args)
{
	char	*result;
	int		nbr;

	nbr = va_arg(args, int);
	result = ft_itoa_base(nbr, 16);
	return (result);
}