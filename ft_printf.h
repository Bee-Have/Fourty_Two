/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 19:12:52 by amarini-          #+#    #+#             */
/*   Updated: 2021/03/15 16:06:58 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int						ft_printf(const char *str, ...);
int						str_data_managment(char *str, int *i, va_list args);

typedef	struct			s_list
{
	int		problem;
	int		length;
	int		neg_len;
	int		len_flag;
	int		padding;
	int		neg_padding;
	char	pad_char;
	char	convert;
	char	*prefix;
	char	*print;
}						t_list;

int						padding_register(char *str, int *i, t_list **list, va_list args);
void					flags_register(t_list **list, char *str, va_list args, int *i);
char					*convert_arg(char *str, va_list args, int index);
void					flags_managment(t_list **list);

t_list					*init_struct(void);
void					ft_free_list(t_list **list);

int						ft_strlen(char *str);
char					*fill_str(char *str, char fill, int length);
char					*str_cpy(char *content);
char					*ft_strjoin(char *dst, char *src);
int						return_to_percent(char *str, int *i, t_list **list);

char					*str_trim(char *str, int length, int start);
char					*make_extention(char fill, int length, char convertion);
int						calculate_padding(int padding, int length);
void					register_negative_padding(char *str, int *i, t_list **list, int *nbr);
int						ft_str_cmp(char c, char *str, char *cmp);

char					*char_to_string(char c);
char					*address_to_string(void *address);
char					*int_to_string(unsigned int nbr);
char					*hexa_to_string(unsigned int nbr, int base);

char					*ft_itoa_base(unsigned long long int n, int base);
char					*ft_itoa(int n);
int						ft_countnbr(long int nbr, int base);
unsigned long long int	ft_check_negative(long int n);
char					*ft_toupper(char *str);

void					ft_write(char c);
void					ft_putstr(char *str);

#endif