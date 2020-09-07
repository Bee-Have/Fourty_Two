/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 08:57:15 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/07 12:53:31 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int		convert_res(const char *str, size_t nbr, int index)
{
	if (str[index] == '-')
		nbr *= -1;
	return (nbr);
}

int		ft_atoi(const char *str)
{
	int					i;
	int					index;
	unsigned long int	res;

	i = 0;
	index = 0;
	res = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	index = i;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (convert_res(str, res, index));
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (convert_res(str, res, index));
}
