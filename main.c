/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 11:02:41 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/17 12:55:48 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void	lstdelone_f(void *d)
{
	free(d);
}

void	*lstmap_f(void *that)
{
	(void)that;
	return ("OK !");
}

int		main(void)
{
	//char	**expected = ((char*[6]){"split  ", "this", "for", "me", "!", NULL});
	char	**result;
	char	*src = "";
	int		i;
	int		j;

	i = 0;
	j = 0;
	//printf("src=%s\n", src);
	//result = ft_split(src, 'z');
	//while (expected[i] != NULL)
	//{
	//	printf("_%s_", expected[i]);
	//	i++;
	//}
	//printf("\n");
	//while (result[j] != NULL)
	//{
	//	printf("_%s_", result[j]);
	//	j++;
	//}
	if (!(result = ft_split(src, 'z')))
		printf("NULL");
	else
		if (!result[0])
			printf("ok\n");
	return (0);
}
