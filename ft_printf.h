/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 19:12:52 by amarini-          #+#    #+#             */
/*   Updated: 2021/01/07 17:40:27 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int		ft_printf(const char *str, ...);
void	str_data_managment(char *str, va_list args);

typedef	struct	s_list
{
	int		length;
	int		padding;
	int		neg_padding;
	char	pad_char;
	char	*print;
}				t_list;
t_list	*init_struct(void);
int	padding_register(char *str, int *i);
t_list	*flags_register(t_list *list, char *str, va_list args, int *i);

int		ft_strlen(char *str);
char	*empty_str(char *str);
char	*str_cpy(char *content);
char	*str_trim(char *str, int start);

void	ft_write(char c);
void	ft_putstr(char *str);

#endif