/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 07:41:07 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/01 08:12:15 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	*calloc(size_t count, size_t size)
{
	char *cp;

	cp = (char *)malloc(count * size);
	if (!cp)
		return (NULL);
	return (cp);
}
