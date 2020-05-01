/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- </var/mail/amarini->              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:38:10 by amarini-          #+#    #+#             */
/*   Updated: 2020/05/01 11:38:14 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<unistd.h>
#include<ctype.h>
#include<string.h>

int     ft_tolower(int c)
{
    if (!c)
        return (0);
    if (c >= 'A' && c <= 'Z')
        c += 32;
    return (c);
}

int     main(void)
{
    char mine = 'A';
    char perf = 'B';
    printf("%d %d\n", mine, perf);
    mine = ft_tolower(mine);
    perf = tolower(perf);
    printf("%d %d\n", mine, perf);
}
