/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 16:34:24 by amarini-          #+#    #+#             */
/*   Updated: 2020/11/05 11:59:28 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include "convert_int/convert_int.h"
# include "flags/flags.h"

int		ft_printf(const char *str, ...);
int		ft_strlen(char *str);
char	*ft_strcpy(char *str);
char	*ft_strjoin(char *dst, char src);
void	ft_putstr(char *str);

#endif