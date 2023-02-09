#include "ft_printf.h"

int	ft_print_d_i(va_list args)
{
	int	num;

	num = va_arg(args, int);
	ft_putnbr(num, 1);
	return (digit_count(num));
}

int	ft_print_u(va_list args)
{
	unsigned int	num;

	num = va_arg(args, unsigned int);
	ft_putnbr_u(num, 1);
	return (digit_count_u(num));
}

void	ft_putnbr(int nb, int fd)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
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
	{
		ft_putchar(nb + 48, fd);
	}
	return ;
}

void	ft_putnbr_u(unsigned int nb, int fd)
{
	if (nb >= 10)
	{
		ft_putnbr(nb / 10, fd);
		nb = nb % 10;
	}
	if (nb < 10)
	{
		ft_putchar(nb + 48, fd);
	}
	return ;
}

int	digit_count_u(unsigned int nb)
{
	unsigned int	i;

	i = 0;
	while (nb != 0)
	{
		nb = nb / 10;
		i++;
		if (nb == 0)
			return (i);
	}
	return (1);
}
