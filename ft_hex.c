/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moeota <moeota@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:58:35 by moeota            #+#    #+#             */
/*   Updated: 2023/02/09 21:21:29 by moeota           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_x(va_list	args)
{
	unsigned int	num;
	int				count;

	count = 0;
	num = va_arg(args, unsigned int);
	ft_putnbr_16(num, 1, &count);
	return (count);
}

int	ft_print_x2(va_list args)
{
	unsigned int	num;
	int				count;

	count = 0;
	num = va_arg(args, unsigned int);
	ft_putnbr_16_a2(num, 1, &count);
	return (count);
}

void	ft_putnbr_16(unsigned int nb, int fd, int *count)
{
	if (nb >= 16)
	{
		ft_putnbr_16(nb / 16, fd, count);
		nb = nb % 16;
	}
	if (nb < 16)
	{
		if (nb < 10)
			ft_putchar(nb + 48, fd);
		else
			ft_putchar('a' + (nb - 10), fd);
		*count += 1;
	}
}

void	ft_putnbr_16_a2(unsigned int nb, int fd, int *count)
{
	if (nb >= 16)
	{
		ft_putnbr_16_a2(nb / 16, fd, count);
		nb = nb % 16;
	}
	if (nb < 16)
	{
		if (nb < 10)
			ft_putchar(nb + 48, fd);
		else
			ft_putchar('A' + (nb - 10), fd);
		*count += 1;
	}
}
