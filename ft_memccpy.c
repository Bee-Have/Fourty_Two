/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- </var/mail/amarini->              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:40:36 by amarini-          #+#    #+#             */
/*   Updated: 2020/05/01 11:40:39 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void    *ft_memccpy(void *dst, void *src, int c, int n)
{
    int i;
    char *cpdest;
    char *cpsrc;

    i = 0;
    cpdest = (char *)dst;
    cpsrc = (char *)src;
    while (i <= n)
    {
        cpdest[i] = cpsrc[i];
        if (cpsrc[i] == (char)c)
            return (dst);
        i++;
    }
    return (dst);
}

int     main(void)
{
    char from1[] = {"this is a test"};
    char from2[] = {"this is also a test"};
    char to[] = {"Hello there general Kenobi"};

    printf("%s\n", to);

    ft_memccpy(to, from1, ' ', 14);
    printf("%s\n", to);

    memccpy(to, from2, ' ', 17);
    printf("%s\n", to);
    }
