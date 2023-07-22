# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvan-der <vvan-der@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/14 16:19:46 by vvan-der          #+#    #+#              #
#    Updated: 2022/12/15 16:30:55 by vvan-der         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADERFILES = ft_printf.h

NAME = libftprintf.a

RM = rm -f

CC = gcc

CFLAGS = -Wall -Werror -Wextra

PRINTF_FILES = ft_bzero.c ft_calloc.c ft_lutoa.c ft_printf.c \
		ft_putchar_fd.c ft_putstrlen_fd.c ft_strchr.c ft_strlen.c ft_writoa.c

O_PRINTF = $(PRINTF_FILES:.c=.o)

$(NAME):	$(O_PRINTF)
		ar rcs $(NAME) $(O_PRINTF)

all:	$(NAME)

%.o : %.c
		$(CC) -c $(CFLAGS) -o $@ $^

clean:
		$(RM) $(O_PRINTF)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re