# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amarini- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/02 09:27:17 by amarini-          #+#    #+#              #
#    Updated: 2020/09/16 13:34:14 by amarini-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRCS = ft_atoi.c ft_isprint.c ft_memset.c ft_strdup.c \
	   ft_strnstr.c ft_bzero.c ft_itoa.c ft_putchar_fd.c \
	   ft_strjoin.c ft_strrchr.c ft_calloc.c ft_memccpy.c \
	   ft_putendl_fd.c ft_strlcat.c ft_strtrim.c ft_isalnum.c \
	   ft_memchr.c ft_putnbr_fd.c ft_strlcpy.c ft_substr.c \
	   ft_isalpha.c ft_memcmp.c ft_putstr_fd.c ft_strlen.c \
	   ft_tolower.c ft_isascii.c ft_memcpy.c ft_split.c \
	   ft_strmapi.c ft_toupper.c ft_isdigit.c ft_memmove.c \
	   ft_strchr.c ft_strncmp.c
BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
		ft_lstmap.c
OBJS = $(SRCS:.c=.o)
OBJBONUS = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(OBJBONUS)
	ar rc $@ $^
	ranlib $@

convert: $(SRCS) $(BONUS)
	$(CC) $(CFLAGS) -c $^

bonus: all

fclean:
	/bin/rm -f *.o

clean: fclean
	/bin/rm -f $(NAME)

re: clean all

.PHONY : fclean clean re all bonus
