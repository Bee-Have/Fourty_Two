/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 09:21:26 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/24 14:48:22 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

int		main(void)
{
	char	*src = "lorem ipsum dolor sit amet";
	char	dst[15] = "rrrrrrrrrrrrrrr";
	char	dst2[15] = "rrrrrrrrrrrrrrr";
	int		res;
	int		res2;

	res = strlcat(dst, src, 5);
	res2 = ft_strlcat(dst2, src, 5);
	printf("good=%d - %s\n", res, dst);
	printf("mine=%d - %s\n", res2, dst2);

	return (0);
}
