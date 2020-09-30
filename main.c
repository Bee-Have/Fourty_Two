/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 09:21:26 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/30 10:49:01 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

int		main(void)
{
	char	*haystack = "je suis albe";
	char	*needle = "je suis albe";

	printf("good=[%s]\n\n", strnstr(haystack, needle, -1));
	printf("mine=[%s]\n\n", ft_strnstr(haystack, needle, -1));

	return (0);
}

/*int		main(int ac, char **av)
{
	if (ac < 3)
		return (0);
	printf("good=[%s]\n", strnstr(av[1], av[2], ft_atoi(av[3])));
	printf("mine=[%s]\n", ft_strnstr(av[1], av[2], ft_atoi(av[3]ss)));

	return (0);
}*/
