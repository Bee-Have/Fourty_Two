/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 07:45:45 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/22 16:27:11 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int		nbr;
	unsigned int		ncopy;
	char				value;

	nbr = 0;
	value = nbr + '0';
	ncopy = n;
	if (n < 0)
	{
		write(fd, "-", 1);
		ncopy = n * -1;
	}
	if (ncopy >= 10)
	{
		nbr = ncopy % 10;
		ncopy = ncopy / 10;
		value = nbr + '0';
		ft_putnbr_fd(ncopy, fd);
		write(fd, &value, 1);
	}
	else if (ncopy < 10)
	{
		value = (ncopy % 10) + '0';
		write(fd, &value, 1);
	}
}
