/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- </var/mail/amarini->              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:39:00 by amarini-          #+#    #+#             */
/*   Updated: 2020/05/01 11:39:02 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void ft_putchar(char a)
{
    write (1, &a, 1);
}

void ft_putstr(char *str)
{
    int i;
    while (str[i] != '\0')
    {
        ft_putchar(str[i]);
        i++;
    }
}

char *ft_itoa(int nb, char *str, int base)
{
    char bs[] = {"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    int nbr;
    int i;
    i = -1;
    nbr = nb;
    while (nbr > 0 )
    {
        i++;
        nbr /= base;
    }
    while (nb > 0)
    {
        nbr = nb % base;
        str[i] = bs[nbr];
        i--;
        nb = nb / base;
    }
    return (str);
}

int     main()
{
    int nb = 346567858;
    int base = 36;
    char str[15];
    printf("%s\n", ft_itoa(nb, str, base));
}
