/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 16:26:41 by amarini-          #+#    #+#             */
/*   Updated: 2020/11/11 12:44:28 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGS_H
# define FLAGS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft/libft.h"

char	*flags_int(char *str, char *flags, int padding);
char	*flags_char(char *str, char *flags, int padding);
int		calc_spaces(char *str, int padding);
char	*fill_pre_sufix(char *str, char fill, int spaces, int i);

#endif