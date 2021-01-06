/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 19:12:52 by amarini-          #+#    #+#             */
/*   Updated: 2021/01/06 21:39:03 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int		ft_printf(const char *str, ...);
t_list	init_struct(void);
typedef struct	s_list
{
	int		length;
	int		padding;
	int		neg_padding;
	int		zero;
	int		neg;
	char	*print;
}				t_list;

#endif