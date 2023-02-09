#include "ft_printf.h"

int	ft_print_c(va_list args)
{
	int	c;

	c = va_arg(args, int);
	write(1, &c, 1);
	return (1);
}

int	ft_print_s(va_list args)
{
	char	*str2;

	str2 = va_arg(args, char *);
	if (str2 == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	return (ft_putstr(str2));
}

int	ft_print_sharp(void)
{
	ft_putchar('%', 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}
