/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- </var/mail/amarini->              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:35:13 by amarini-          #+#    #+#             */
/*   Updated: 2020/05/01 11:35:17 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>
#include<string.h>

int		ft_strlcat(char *dst, char *src, int dstsize)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dst[i] != '\0' && i < dstsize)
		i++;
	while (src[j] != '\0' && i < (dstsize - 1))
    {
        dst[i] = src[j];
        i++;
		j++;
    }
    dst[i] = '\0';
    return (i);
}

int		main(void)
{
    char dst[11] = {"Hello"};
    char src[] = {"World"};

    char dstalt[11] = {"Hello"};
    char srcalt[] = {"World"};

    printf("%s %s\n%s %s\n\n", dst, src, dstalt, srcalt);
    printf("%d\n", ft_strlcat(dst, src, 11));
    printf("%lu\n", strlcat(dstalt, srcalt, 11));
    printf("%s %s\n%s %s\n\n", dst, src, dstalt, srcalt);
}
