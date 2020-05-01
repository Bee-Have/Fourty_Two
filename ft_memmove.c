/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- </var/mail/amarini->              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:39:16 by amarini-          #+#    #+#             */
/*   Updated: 2020/05/01 11:39:20 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void *ft_memmove(void *dst, void *src, int len)
{
    int i;
    char tempdst[len];
    char *cpdst;
    char *cpsrc;

    i = 0;
    cpdst = (char *)dst;
    cpsrc = (char *)src;
    while (i < len)
    {
        tempdst[i] = cpsrc[i];
        i++;
    }
    i = 0;
    while (i < len)
    {
        cpdst[i] = tempdst[i];
        i++;
    }
    return (dst);
}

int     main(void)
{
    char from1[14] = {"this is a test"};
    char from2[17] = {"this is also test"};
    char to[17];

    printf("%s\n", to);

    ft_memmove(to, from1, 14);
    printf("%s\n", to);

    memmove(to, from2, 17);
    printf("%s\n", to);
}
