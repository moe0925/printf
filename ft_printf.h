/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moeota <moeota@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:58:35 by moeota            #+#    #+#             */
/*   Updated: 2023/02/09 15:52:46 by moeota           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H
//------------------------------------------------
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

//------------------------------------------------
//  マクロ定義(Macro definition)
//------------------------------------------------

//------------------------------------------------
//  型定義(Type definition)
//------------------------------------------------


//------------------------------------------------
//  プロトタイプ宣言(Prototype declaration)
//------------------------------------------------
int		ft_printf(const char *memo, ...);

char	*ft_strchr(const char *s, int c);

char	*ft_strchr_write(const char *s, int c);

void     ft_putnbr(int nb, int fd);

void	    ft_putnbr_16(unsigned int nb, int fd,int *count);

int     ft_putstr(char *str);

void	ft_putptr_16(uintptr_t nb, int fd,int *count);

void	ft_putnbr_16_A(unsigned int nb, int fd, int *count);

void	ft_putnbr_u(unsigned int nb, int fd);

int     ft_putchar(char c, int fd);

size_t	ft_strlen(const char *s);

int     digit_count(int nb);

int digit_count_u(unsigned int nb);

int	ft_print_c(va_list args);

int	ft_print_s(va_list args);

int ft_print_d_i(va_list args);

int	ft_print_u(va_list args);

int ft_print_p(va_list args);

int ft_print_x(va_list args);

int ft_print_X(va_list args);


int ft_print_sharp();


#endif