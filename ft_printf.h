/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moeota <moeota@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:58:35 by moeota            #+#    #+#             */
/*   Updated: 2022/12/06 10:09:35 by moeota           ###   ########.fr       */
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

void	ft_putnbr_16(int nb, int fd);

int     ft_putstr(char *str);

void	ft_putnbr_16_A(int nb, int fd);

int     ft_putchar(char c, int fd);

size_t	ft_strlen(const char *s);

int     digit_count(int nb);


#endif