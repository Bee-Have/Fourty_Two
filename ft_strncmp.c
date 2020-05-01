/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- </var/mail/amarini->              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:41:03 by amarini-          #+#    #+#             */
/*   Updated: 2020/05/01 11:41:06 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>
#include<string.h>

int     ft_strncmp(char *s1, char *s2, int n)
{
    int i;

    i = 0;
    while (i < n)
    {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    return (0);
}

int     main(void)
{
    char *s1 = {" Hello there general Kenobi"};
    char *s2 = {"Hello there general Kenobi!"};

    printf("%d\n", ft_strncmp(s1, s2, 20));
    printf("%d\n", strncmp(s1, s2, 20));
}
