# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vincent <vincent@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/14 16:19:46 by vvan-der          #+#    #+#              #
#    Updated: 2023/07/22 15:21:33 by vincent          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
RM		= rm -rf
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra

SRCS	= ft_bzero.c ft_calloc.c ft_lutoa.c ft_printf.c \
		ft_putchar_fd.c ft_putstrlen_fd.c ft_strchr.c ft_strlen.c ft_writoa.c

OBJS	= $(SRCS:%.c=$(OBJDIR)/%.o)
OBJDIR	= printobjs

all:	$(NAME)

$(NAME): $(OBJDIR) $(OBJS)
		ar rcs $(NAME) $(OBJS)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o : %.c
		$(CC) -c $(CFLAGS) -o $@ $^

clean:
		$(RM) $(OBJDIR)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re