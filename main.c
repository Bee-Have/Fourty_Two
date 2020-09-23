/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 09:21:26 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/23 16:11:20 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int		main(int argc, char **argv)
{
	char	*result;

	if (argc == 1)
		return (0);
	result = ft_strtrim(argv[1], argv[2]);
	printf("%s\n", result);

	return (0);
}
