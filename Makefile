# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moeota <moeota@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 22:58:35 by moeota            #+#    #+#              #
#    Updated: 2022/12/06 11:05:08 by moeota           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

CC = gcc

NAME = libftprintf.a

OBJS = ft_printf.o ft_printf_utils.o


all: 		$(NAME) 

$(NAME): $(OBJS)
	 $(AR) cr $@ $^


clean:
	-$(RM) $(OBJS) $(BONUSOBJS)

fclean: clean
	-$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re

