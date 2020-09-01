/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 07:40:23 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/01 07:40:33 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_atoi(const char *str)
{
	int			i;
	long int	res;

	i = 0;
	res = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	if (res >= 2147483647)
	{
		if (str[0] != '-' && res == 2147483647)
			return (res);
		else if (str[0] == '-' && res == 2147483648)
			return (-2147483648);
		if (res >= 2147483648)
		{
			return (0);
		}
	}
	if (str[0] == '-')
		res *= -1;
	return (res);
}
