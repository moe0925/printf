/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moeota <moeota@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:56:25 by moeota            #+#    #+#             */
/*   Updated: 2022/12/26 15:45:30 by moeota           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int divided_case(char *str,  va_list args)
{
	char *spec;

	spec = str +1;
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
		if (str2 == NULL)
		{
			write(1,"(null)",6);
			return (6);
		}
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
		if (num < 0)
		{
			
		}
		ft_putnbr(num,1);
		return (digit_count(num));

	}
	
	else if (*spec == 'p' )
	{
		unsigned long long p;
		int count;

		p = (va_arg(args, unsigned long long));
		count = 0;
		if (*spec == 'p')
			write(1, "0x", 2);
		ft_putptr_16(p,1,&count);
		return(count + 2);
	}
	
	else if (*spec == 'x' || *spec == 'X')
	{
		int num;
		int count;

		count = 0;
		num = va_arg(args,unsigned long long);
		ft_putnbr_16(num,1,&count);
		return (count);
	}
	
	else if (*spec == '%')
	{
		ft_putchar('%',1);
		return (1);
	}
	return (0);
}

int check(const char *str)
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
	va_list args;

	char *find;
	int return_length;
	find = (char * )str;

	return_length = 0;


	va_start(args, str);
	
	while (find)
	{
		return_length += check(find);
		find = ft_strchr_write(find, '%');
		if (find)
		{
			// printf("%c",va_arg(args, char));
			return_length += divided_case(find, args);
			find += 2;
			va_arg(args,int);
		}
	}


	va_end(args);
	return (return_length);
}

// #include <limits.h>
// int main()
// {
// 	// char *memo = "arg_2:%p";
//     // int  a = '3';//test1
// 	// char *a = "12345";
// 	// int num = 123456;
// 	int d;
// 	int c;
// 	char *p;
// 	// p = "12345";
// 	// unsigned int num2 = -234567;
//     // double arg_3 = 3.14;
//   	// pritnf("set1:%c",a);
// 	printf("-----------------answer1----------------\n");
// 	// ft_printf("set1:%p--------",p);
// 	// d = printf("set1:%pans\n",num);
// 	// printf("set1:%d\n",num);
// 	// d = printf(" %c %c %c ", '0', 0, '1');
//     // c  = printf(" %d ", -9);
//     // d = printf("%d ", num);
// 	c = -123456;
// 	d = printf("%x",-123);
// 	printf("%d",d);
// 	// printf("%d", d);

// 	// d = printf("%d\n", INT_MIN);
// 	// printf("%d", d);
// 	// // d = ft_printf(" %d ", num);

// 	// printf("d:%d", d);

// 	// d = printf(" %c %c %c ", '1', '2', '3');
// 	// printf("~~~~%X~~~~~\n",d);
// 	printf("-----------------answer2----------------\n");
// 	// ft_printf("set1:%Xans",num);
// 	d = ft_printf("%x", -123);
// 	printf("%d",d);
// 	// d = -100;
// 	// ft_printf("%d", d);
// 	// ft_printf("d:%u", d);
//     // c  = ft_printf(" %d ", -9);
// 	// d = ft_printf("%d\n", INT_MIN);
// 	printf("-----------------answer3----------------\n");
// 	// ft_printf("%d", d);
//     d = ft_printf(" %u\n ", c);
//     printf(" %d ",d);

// 	d = ft_printf(" %c %c %c ", '1', '2', '3');
// 	// d = ft_printf("%c", '1');
// 	// ft_printf("%s",p);
// 	// printf("~~~~%X~~~~~\n",d);
// 	return (0);


// }



// // // // void func(char *arg_1, ...) {
// // // //     va_list ap;
// // // //     va_start(ap, arg_1);
// // // //     printf("arg_2: %d\n", va_arg(ap, int));
// // // //     printf("arg_3: %lf\n", va_arg(ap, double));

// // //     ~処理~

// // }
// // int main(void) {
// //     char *arg_1 = "aaaaa";
// // //     int arg_2 = 5;
// // //     double arg_3 = 3.14;

// // //     func(arg_1, arg_2, arg_3);
// // // }