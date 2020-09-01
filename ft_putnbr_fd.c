/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 07:45:45 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/01 08:23:50 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putnbr_fd(int n, int fd)
{
	int		nbr;
	char	value;

	nbr = 0;
	value = nbr;
	if (n >= 10)
	{
		nbr = n % 10;
		n = n / 10;
		value = nbr + '0';
		ft_putnbr_fd(n, fd);
		write(fd, &value, 1);
	}
	else if (n < 10)
	{
		value = (n % 10) + '0';
		write(fd, &value, 1);
	}
}
