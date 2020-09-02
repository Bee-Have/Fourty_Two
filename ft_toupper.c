/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 09:19:40 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/02 09:20:59 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		ft_toupper(int c)
{
	if (!c)
		return (0);
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
