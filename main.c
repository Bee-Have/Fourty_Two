/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 08:38:04 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/10 12:14:26 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

int		main(void)
{
	char	*result;
	char	*str;
	char	*set;

	str = ft_strdup(str);
	set = ft_strdup(set);
	str = "  \n  \t  lorem \n ipsum \t dolor \n sit \t amet  \t \n ";
	set = "\t \n";
	printf("%s\n", str);
	result = ft_strtrim(str, set);
	printf("%s\n", result);

	return (0);
}
