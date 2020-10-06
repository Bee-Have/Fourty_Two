/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarini- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 11:09:46 by amarini-          #+#    #+#             */
/*   Updated: 2020/09/22 11:16:33 by amarini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

int		get_next_line(int fd, char **line);
int		ft_strlen(char *str);
int		check_newline(char *str, int read);
char	*fill_leftover(char const *src, char *dst, int *index);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char *str, unsigned int start, size_t len);

#endif
