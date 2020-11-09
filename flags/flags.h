/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 16:26:41 by amarini-          #+#    #+#             */
/*   Updated: 2020/11/09 14:19:57 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGS_H
# define FLAGS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

char	*flags_int(char *result, char *flags, int padding);
char	*flags_char(char *result, char *flags, int padding);

#endif