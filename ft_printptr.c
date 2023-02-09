#include "ft_printf.h"

int ft_print_p(va_list args)
{
	unsigned long long p;
	int count;

	p = (va_arg(args, unsigned long long));
	count = 0;
	write(1, "0x", 2);
	ft_putptr_16(p,1,&count);
	return(count + 2);
}


