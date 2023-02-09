# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moeota <moeota@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 22:58:35 by moeota            #+#    #+#              #
#    Updated: 2022/12/26 18:20:17 by moeota           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

CC = gcc

NAME = libftprintf.a

OBJS = ft_printf.o ft_printf_utils.o ft_print.o  ft_hex.o ft_print_nbr.o ft_printptr.o

INCDIR  = -I src


all: 		$(NAME) 

$(NAME): $(OBJS)
	 $(AR) cr $@ $^


clean:
	-$(RM) $(OBJS) $(BONUSOBJS)

fclean: clean
	-$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re

