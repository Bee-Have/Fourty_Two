/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- </var/mail/amarini->              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:37:48 by amarini-          #+#    #+#             */
/*   Updated: 2020/05/01 11:37:51 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>
#include<string.h>

int     ft_strlcpy(char *dst, char *src, unsigned long int size)
{
    int i;

    i = 0;
    if (size < 0)
        return (0);
    while (src[i] != '\0' && size > 1)
    {
        dst[i] = src[i];
        i++;
        size--;
    }
    dst[i] = '\0';
    return (i);
}

int     main(void)
{
    char dst[] = {"Hello"};
    char src[] = {"World"};

    char dstalt[] = {"Hello"};
    char srcalt[] = {"World"};

    printf("%s %s\n%s %s\n\n", dst, src, dstalt, srcalt);
    printf("%d\n", ft_strlcpy(dst, src, 6));
    printf("%lu\n", strlcpy(dstalt, srcalt, 6));
    printf("%s %s\n%s %s\n\n", dst, src, dstalt, srcalt);
}
