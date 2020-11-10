/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifications.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 14:17:51 by amarini-          #+#    #+#             */
/*   Updated: 2020/11/10 10:19:57 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPECIFICATIONS_H
# define SPECIFICATIONS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include "convert_int/convert_int.h"

char	*spec_c(va_list args);
char	*spec_s(va_list args);
char	*spec_p(va_list args);
char	*spec_di(va_list args);
char	*spec_u(va_list args);
char	*spec_xX(va_list args);
char	*spec_percentage(va_list args);
char	*ft_strjoin(char *dst, char *src);

#endif