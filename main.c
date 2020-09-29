/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 09:21:26 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/29 09:50:06 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"


int		main(int ac, char **av)
{
	int		res;
	int		myres;

	if (ac < 2)
		return (1);
	res = atoi((const char *)av[1]);
	myres = ft_atoi((const char *)av[1]);

	printf("good=%d\n", res);
	printf("mine=%d\n", myres);

	return (0);
}
