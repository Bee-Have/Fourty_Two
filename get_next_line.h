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

int		ft_strlen(char *str);
int		find_newline(char *str, int read);
int		read_fd(int fd, int *index, char **leftover);
int		get_next_line(int fd, char **line);
char	*fill_str(char *dst, char *src, int idst, int maxlen);
char	*ft_strjoin(char const *dst, char const *src);
char	*ft_substr(char *str, int start, int len, int line);

#endif
