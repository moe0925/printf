
#include "ft_printf.h"

int	ft_print_d_i(va_list args)
{
	int num;
	num = va_arg(args, int);
	ft_putnbr(num,1);
	return (digit_count(num));
}

int	ft_print_u(va_list args)
{
	unsigned int num;
	num = va_arg(args,unsigned int);
	ft_putnbr_u(num,1);
	return (digit_count_u(num));
}
