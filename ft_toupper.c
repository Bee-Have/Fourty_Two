/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- </var/mail/amarini->              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:40:00 by amarini-          #+#    #+#             */
/*   Updated: 2020/05/01 11:40:04 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<unistd.h>
#include<ctype.h>
#include<string.h>

int     ft_toupper(int c)
{
    if (!c)
        return (0);
    if (c >= 'a' && c <= 'z')
        c -= 32;
    return (c);
}

int     main(void)
{
    char mine = 'A';
    char perf = 'B';
    printf("%d %d\n", mine, perf);
    mine = ft_toupper(mine);
    perf = toupper(perf);
    printf("%d %d\n", mine, perf);
}
