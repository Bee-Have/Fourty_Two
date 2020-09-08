/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 09:24:18 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/08 16:55:06 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static	int		ft_countnbr(int n)
{
	int		count;

	count = 0;
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char			*ft_itoa(int n)
{
	int		ncount;
	int		nbr;
	char	*str;

	ncount = 0;
	ncount = ft_countnbr(n) + 1;
	nbr = n;
	str = (char *)malloc(ncount * sizeof(char));
	if (!str)
		return (NULL);
	str[ncount] = '\0';
	ncount--;
	printf("%d\n", ncount);
	while (ncount > 0)
	{
		nbr = n % 10;
		str[ncount] = nbr + '0';
		ncount--;
		printf("%d\n", ncount);
		n = n / 10;
		nbr = n;
	}
	if (ncount >= 0)
		str[ncount] = nbr + '0';
	return (str);
}
