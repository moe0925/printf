#include "ft_printf.h"

int ft_printf(const char *memo, ...)
{
	va_list ap;
	va_start(ap, memo);
	char *temp;
	int i;
	printf("arg_2: %d\n", va_arg(ap, int));
	printf("arg_3: %lf\n", va_arg(ap, double));

	temp = (ft_strchr(memo, '%'));

	if (temp != 0)
	{

	while ((temp - memo) !=0)
	{
		write(1, &memo,1);
		memo++;
	}




	}
	


	va_end(ap);
	return (0);

	
}

int main()
{
	char *memo = "aaaaa";
    char  *arg_2 = "12345678";
    double arg_3 = 3.14;

	ft_printf(memo, arg_2);
}