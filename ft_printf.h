/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 16:34:24 by amarini-          #+#    #+#             */
/*   Updated: 2020/11/10 10:29:22 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include "flags/flags.h"
# include "specs/specifications.h"
# include "specs/convert_int/convert_int.h"

int		ft_printf(const char *str, ...);
int		sort_behavior(va_list args, char *spec);
int		check_flag(va_list args, char *str);
int		ft_strlen(char *str);
void	ft_putchar(char c);
void	ft_putstr(char *str);
char	*ft_strjoin_char(char *str, char c);
char	*no_spec(char *str);
//char	*ft_strcpy(char *str);
//char	*ft_strjoin(char *dst, char src);

#endif