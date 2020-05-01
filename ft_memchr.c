/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- </var/mail/amarini->              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:41:38 by amarini-          #+#    #+#             */
/*   Updated: 2020/05/01 11:41:41 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void    *ft_memchr(void *s, int c, int n)
{
    int i;
    char *cps;

    i = 0;
    cps = (char *)s;
    while (i < n)
    {
        if (cps[i] == (char)c)
            return (&cps[i]);
        i++;
    }
    return (NULL);
}

int    main(void)
{
    char origin[] = {"Hello there general Kenobi"};

    printf("%s\n", (char *)memchr(origin, 'g', 20));
    printf("%s\n", (char *)ft_memchr(origin, 'g', 20));
    return (0);
}
