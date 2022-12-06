/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moeota <moeota@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:56:25 by moeota            #+#    #+#             */
/*   Updated: 2022/12/06 11:04:31 by moeota           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int divided_case(char *find,  va_list args)
{
	char *spec;

	spec = find +1;
	if (*spec == 'c')
	{
		int c;
		c = va_arg(args,int); 
		write(1, &c, 1);
		return (1);
	}
	else if (*(spec) == 's')
	{
		char *str2;
		str2 = va_arg(args,char *);
		return(ft_putstr(str2));
	}
	else if (*spec == 'd' || *spec == 'i')
	{
		int num;
		num = va_arg(args, int);
		ft_putnbr(num,1);
		return (digit_count(num));
		
	}
	else if (*spec == 'u')
	{
		unsigned int num;
		num = va_arg(args,unsigned int);
		ft_putnbr(num,1);
		return (digit_count(num));

	}
	
	else if (*spec == 'p' || *spec == 'x')
	{
		int p;
		p = (va_arg(args,int));
		if (*spec == 'p')
			write(1, "0x", 2);
		ft_putnbr_16_A(p,1);
		return (digit_count(p) + 1);

	}
	else if (*spec == 'X')
	{
		int num;
		num = va_arg(args,int);
		ft_putnbr_16(num,1);
		return (digit_count(num) + 1);

	}
	
	else if (*spec == '%')
	{
		ft_putchar('%',1);
		return (1);
	}
	return (0);
}

int check(char *str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
	{
		if (str[i] == '%')
			return (i);
		i++;
	}
	return (i);
}

int ft_printf(const char *str, ...)
{
	va_list ap;
	va_start(ap, str);
	char *find;
	int return_length;
	find = (char * )str;

	return_length = 0;
	
	while (find)
	{
		return_length += check(find);
		find = ft_strchr_write(find, '%');
		if (find)
		{
			return_length += divided_case(find, str,ap);
			find += 2;
		}
	}
	
	// return_length = find;	

	// printf("arg_2: %s\n",str);//test

	va_end(ap);
	return (return_length);
}

int main()
{
	// char *memo = "arg_2:%p";
    // int  a = '3';//test1
	// char *a = "12345";
	int num = 123456;
	int d;
	// char *p;
	// p = "12345";
	// unsigned int num2 = -234567;
    // double arg_3 = 3.14;
  	// pritnf("set1:%c",a);
	printf("-----------------answer1----------------\n");
	// ft_printf("set1:%p--------",p);
	d = printf("set1:%pans\n",num);
	// printf("set1:%d\n",num);

	printf("~~~~%X~~~~~\n",d);
	printf("-----------------answer2----------------\n");
	// ft_printf("set1:%Xans",num);
	d = ft_printf("set1:%pans\n",num);
	printf("~~~~%X~~~~~\n",d);



}



// void func(char *arg_1, ...) {
//     va_list ap;
//     va_start(ap, arg_1);
//     printf("arg_2: %d\n", va_arg(ap, int));
//     printf("arg_3: %lf\n", va_arg(ap, double));

//     ~処理~

// }
// int main(void) {
//     char *arg_1 = "aaaaa";
//     int arg_2 = 5;
//     double arg_3 = 3.14;

//     func(arg_1, arg_2, arg_3);
// }