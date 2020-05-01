/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- </var/mail/amarini->              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:38:31 by amarini-          #+#    #+#             */
/*   Updated: 2020/05/01 11:38:37 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int     ft_isalnum(int c)
{
    if (c >= '0' && c <= '9')
        return (1);
    else if (c >= 'A' && c <= 'Z')
        return (1);
    else if (c >= 'a' && c <= 'z')
        return (1);
    return (0);
}

int 	main(void)
{
	int i = 0;
	char test[] = "H3110 th3r3 g3n3r41 K3n0b1";

	printf("%s\n", test);
	while (test[i] != '\0')
	{
		printf("%d", ft_isalnum(test[i]));
		i++;
	}
	printf("\n");
	i = 0;
	while (test[i] != '\0')
	{
		printf("%d", isalnum(test[i]));
		i++;
	}
}
