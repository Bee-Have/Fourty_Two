/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <amarini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 15:22:42 by amarini-          #+#    #+#             */
/*   Updated: 2020/10/29 16:27:23 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_INT_H
# define CONVERT_INT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

char	*ft_itoa(int n);
char	*ft_itoa_base(int n, int base);
int		ft_countnbr(int n, int nbr, int base);
int		ft_check_negative(int n);

#endif