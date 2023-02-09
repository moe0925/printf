#include "ft_printf.h"

int	ft_print_p(va_list args)
{
	unsigned long long	p;
	int					count;

	p = (va_arg(args, unsigned long long));
	count = 0;
	write(1, "0x", 2);
	ft_putptr_16(p, 1, &count);
	return (count + 2);
}

void	ft_putptr_16(uintptr_t nb, int fd, int *count)
{
	if (nb >= 16)
	{
		ft_putptr_16(nb / 16, fd, count);
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
