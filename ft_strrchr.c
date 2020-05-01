/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- </var/mail/amarini->              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:35:31 by amarini-          #+#    #+#             */
/*   Updated: 2020/05/01 11:35:36 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<unistd.h>
#include<string.h>

char    *ft_strrchr(char *s, int c)
{
    int i;
    int oc;

    i = 0;
    oc = 0;
    while (s[i] != '\0')
    {
        if (s[i] == c)
            oc = i;
        i++;
    }
    if (oc == 0 && s[oc] != c)
        return (NULL);
    return (&s[oc]);
}

int     main(void)
{
    char *str = {"Hello There General Kenobi!"};

    printf("%s\n", strrchr(str, 'H'));
    printf("%s\n", ft_strrchr(str, 'H'));
}
