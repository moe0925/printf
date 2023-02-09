#include "ft_printf.h"

int ft_print_x(va_list args)
{
	unsigned  int  num;
	int count;

	count = 0;
	num = va_arg(args,unsigned int);
	ft_putnbr_16(num,1,&count);
	return (count);
}

int ft_print_X(va_list args)
{
	unsigned  int  num;
	int count;

	count = 0;
	num = va_arg(args,unsigned int);
	ft_putnbr_16_A(num,1,&count);
	return (count);
}

