/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- </var/mail/amarini->              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:42:08 by amarini-          #+#    #+#             */
/*   Updated: 2020/05/01 11:42:13 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>
#include<string.h>

char *ft_strnstr(char *haystack, char *needle, int len)
{
    int i;
    int j;

    i = 0;
    j = 0;
    if (!needle)
        return (haystack);
    while (haystack[i] != '\0' && i < len)
    {
        while (haystack[i] == needle[j])
        {
            i++;
            j++;
        }
        if (needle[j] == '\0')
            return (&haystack[i - j]);
		else
			i++;
    }
    return (NULL);
}

int     main(void)
{
    char hay[] = {"Hello there general Kenobi !"};
    char nee[] = {"xy"};

    printf("%s\n", ft_strnstr(hay, nee, 20));
    printf("%s\n", strnstr(hay, nee, 20));
}
