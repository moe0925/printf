/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moeota <moeota@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:56:25 by moeota            #+#    #+#             */
/*   Updated: 2022/12/05 20:35:47 by moeota           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

char	*ft_strchr(const char *s, int c)
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
			i++;
	}
	return (NULL);
}

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
			write(1,&s2[i],1);
			i++;
		}
	}
	return (NULL);
}

int ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
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



void	ft_putnbr(int nb, int fd)
{
	if (nb < 0)
	{
		ft_putchar('-', fd);
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10, fd);
		nb = nb % 10;
	}
	if (nb < 10)
		ft_putchar(nb + 48, fd);
}

void	ft_putnbr_16(int nb, int fd)
{
	if (nb < 0)
	{
		ft_putchar('-', fd);
		nb = -nb;
	}
	if (nb >= 16)
	{
		ft_putnbr_16(nb / 16, fd);
		nb = nb % 16;
	}
	if (nb < 16)
	{
		if (nb < 10)
			ft_putchar(nb + 48, fd);
		else
			ft_putchar('A' + (nb - 10), fd);
	}
	
}

void	ft_putnbr_16_A(int nb, int fd)
{
	if (nb < 0)
	{
		ft_putchar('-', fd);
		nb = -nb;
	}
	if (nb >= 16)
	{
		ft_putnbr_16_A(nb / 16, fd);
		nb = nb % 16;
	}
	if (nb < 16)
	{
		if (nb < 10)
			ft_putchar(nb + 48, fd);
		else
			ft_putchar('a' + (nb - 10), fd);
	}
	
}

size_t	ft_strlen(const char *s)
{
	int		i;
	char	*str2;

	i = 0;
	str2 = (char *)s;
	while (str2[i] != '\0')
	{
		i++;
	}
	return (i);
}

// void	ft_putnbr_u(unsigned int nb, int fd)
// {
// 	if (nb >= 10)
// 	{
// 		ft_putnbr(nb / 10, fd);
// 		nb = nb % 10;
// 	}
// 	if (nb < 10)
// 		ft_putchar(nb + 48, fd);
// }

