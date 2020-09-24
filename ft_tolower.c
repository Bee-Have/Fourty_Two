/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 09:16:41 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/02 09:18:05 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		ft_tolower(int c)
{
	if (!c)
		return (0);
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}