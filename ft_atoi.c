/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 08:57:15 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/01 09:10:02 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
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
		if ((str[0] != '-' && res == 2147483647)
				|| (str[0] == '-' && res == 2147483648))
			return (res);
		if (res >= 2147483648)
			return (0);
	}
	if (str[0] == '-')
		res *= -1;
	return (res);
}
