/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moeota <moeota@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:56:25 by moeota            #+#    #+#             */
/*   Updated: 2023/02/09 15:54:11 by moeota           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

char	*ft_strchr_write(const char *s, int c)
{
	int		i;
	char	*s2;

	while (c > 256)
		c = c % 256;
	s2 = (char *)s;
	i = 0;
	if (c == 0)
	{
		while (s2[i] != '\0')
			i++;
		return (&(s2[i]));
	}
	while (s2[i] != '\0')
	{
		if (s2[i] == (char)c)
			return (&s2[i]);
		else
		{
			write(1, &s2[i], 1);
			i++;
		}
	}
	return (NULL);
}

int	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

static void	ex_intmin(int fd)
{
	write(fd, "-2147483648", 11);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ex_intmin(fd);
		return ;
	}
	ft_putnbr(n, fd);
	return ;
}

int	digit_count(int nb)
{
	int	i;

	i = 0;
	if (nb == -2147483648)
		return (11);
	if (nb < 0)
	{
		i++;
		nb = -nb;
	}
	while (nb != 0)
	{
		nb = nb / 10;
		i++;
		if (nb == 0)
			return (i);
	}
	return (1);
}
