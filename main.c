/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 09:21:26 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/24 16:03:34 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"


int		main(void)
{
	char	*haystack = "The most merciful thing in the world, I think, is the inability of the human mind to correlate all its contents.";
	char	needle[1];
	//char	*res;
	char	*myres;
	//int		len;

	needle[0] = '\0';
	//len = ft_strlen(haystack);
	//res = strnstr(NULL, needle, 13);
	myres = ft_strnstr(haystack, needle, 13);
	printf("mine=%s\n", myres);
	//printf("good=%s\n", res);

	return (0);
}
