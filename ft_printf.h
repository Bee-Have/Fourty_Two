/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 19:12:52 by amarini-          #+#    #+#             */
/*   Updated: 2021/01/13 12:57:00 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int				ft_printf(const char *str, ...);
int			str_data_managment(char *str, int *i, va_list args);

typedef	struct	s_list
{
	int		length;
	int		padding;
	int		neg_padding;
	char	pad_char;
	char	convert;
	char	*print;
}				t_list;
t_list			*init_struct(void);
int				padding_register(char *str, int *i);
void			flags_register(t_list **list, char *str, va_list args, int *i);
char			*convert_arg(char *str, va_list args, int index);

int				ft_strlen(char *str);
char			*fill_str(char *str, char fill, int length);
char			*str_cpy(char *content);
char			*str_trim(char *str, int start);
char			*ft_strjoin(char *dst, char *src);

char			*char_to_string(char c);
char			*address_to_string(unsigned int nbr);
char			*int_to_string(unsigned int nbr);
char			*hexa_to_string(unsigned int nbr);

char			*ft_itoa_base(unsigned int n, int base);
char			*ft_itoa(int n);
int				ft_countnbr(long int nbr, int base);
unsigned int	ft_check_negative(long int n);
char			*ft_toupper(char *str);

void			ft_write(char c);
void			ft_putstr(char *str);

#endif