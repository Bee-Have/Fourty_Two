/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 14:30:22 by amarini-          #+#    #+#             */
/*   Updated: 2020/05/02 14:30:35 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int ft_atoi(char *str)
{
    int i;
    long int res;

    i = 0;
    res = 0;
    if (!str)
        return (0);
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i] != '\0')
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        res = (res * 10) + (str[i] - '0');
        i++;
    }
    if (res >= 2147483647)
    {
        if (str[0] != '-' && res == 2147483647)
            return (res);
        else if (str[0] == '-' && res == 2147483648)
            return (-2147483648);
        if (res >= 2147483648)
        {
            return (0);
        }
    }
    if (str[0] == '-')
        res *= -1;
    return (res);
}

int main(int argc, char **argv)
{
    if (argc && argc != 0)
    {
        printf("perf= %d\n", atoi(argv[1]));
        printf("mine= %d\n", ft_atoi(argv[1]));
    }
    return (0);
}
