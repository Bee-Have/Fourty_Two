/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- </var/mail/amarini->              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:40:51 by amarini-          #+#    #+#             */
/*   Updated: 2020/05/01 11:40:55 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>
#include<string.h>

void *ft_memset(void *b, int c, int len)
{
    int i;
    char *tab;

    tab = (char *)b;
    i = 0;
    while (i < len)
    {
        tab[i] = (char)c;
        i++;
    }
    return (b);
}

int main(void)
{
    char pointer[] = {"1234567890"};
    printf("%s\n", pointer);

    ft_memset(pointer, '2', 5);
    printf("%s\n", pointer);

    memset(pointer, 49, 5);
    printf("%s\n", pointer);
}
