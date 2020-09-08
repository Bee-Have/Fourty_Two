/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 08:38:04 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/08 09:09:46 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

int		main(void)
{
	char	*string1 = "abcdefghij";
	char	*string2 = "abcdefgxyz";

	printf ("good=%d\nmine=%d\n", memcmp(string1, string2, 7), 
			ft_memcmp(string1, string2, 7));

	return (0);
}
