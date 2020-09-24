/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 07:45:21 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/14 15:53:11 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putendl_fd(char *s, int fd)
{
	int	length;

	length = 0;
	if (!s || !fd)
		return ;
	while (s[length] != '\0')
		length++;
	write(fd, s, length);
	write(fd, "\n", 1);
}