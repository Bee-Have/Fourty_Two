/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 07:45:01 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/03 09:01:29 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putstr_fd(char *s, int fd)
{
	int		length;

	length = 0;
	while (s[length] != '\0')
		length++;
	write(fd, s, length);
}
