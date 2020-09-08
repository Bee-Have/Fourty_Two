/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 08:38:04 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/08 11:37:09 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

int		main(void)
{
	char	dest1[26] = "hello there";
	char	*dest2 = "hello there";
	char	*src = "princesse b*tch";
	
	printf("good=%lu %s\nmine=%lu %s\n", strlcat(dest1, src, 26), dest1, 
			ft_strlcat(dest2, src, 26), dest2);

	return (0);
}
