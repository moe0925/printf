/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moeota <moeota@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:56:25 by moeota            #+#    #+#             */
/*   Updated: 2023/02/09 15:57:16 by moeota           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int divided_case(char *str,  va_list args)
{
	char *spec;

	spec = str +1;    
	if (*spec == 'c')
		return (ft_print_c(args));
	else if (*(spec) == 's')
		return (ft_print_s(args));
	else if (*spec == 'd' || *spec == 'i')
		return (ft_print_d_i(args));
	else if (*spec == 'u')
		return (ft_print_u(args));
	else if (*spec == 'p')
		return (ft_print_p(args));
	else if (*spec == 'x')
		return (ft_print_x(args));
	else if (*spec == 'X')
		return (ft_print_X(args));	
	else if (*spec == '%')
		return (ft_print_sharp());
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
    int count;

	find = (char * )str;
    count = 2;
	return_length = 0;
	va_start(args, str);
	while (find)
	{
		return_length += check(find);

		find = ft_strchr_write(find, '%');
		if (find)
		{
			return_length += divided_case(find, args);
			find += count;
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
// 	// int *num = 123456;
// 	int d;
// 	int c;
//     // int a;
// 	char *p;


// 	int a = 10;
// 	// int b = 100000;
// 	// printf("%u", -100);
// 	// ft_printf("%u", -100);
// 	// printf("[%14d]\n", a);

// 	// printf(" %c %c %c ", '0', 0, '1');

// 	printf(" %c %c %c ", ' ', ' ', ' ');

// 	// printf(" %c %c %c ", '1', '2', '3');

// 	// printf(" %c %c %c ", '2', '1', 0);
// 	// printf(" %c %c %c ", 0, '1', '2');

// 	// ft_printf(" %c %c %c ", '0', 0, '1');
// 	ft_printf("answer;%c %c %c ", 'a', 'a', 'a');
// 	ft_printf(" %c %c %c ", '1', '2', '3');
// 	ft_printf(" %c %c %c ", '2', '1', 0);
// 	// ft_printf(" %c %c %c ", 0, '1', '2');
// 	// ft_printf("-------------------------%d",1);
// 	// p = "12345";
// 	// unsigned int num2 = -234567;
//     // double arg_3 = 3.14;
//   	// pritnf("set1:%c",a);
// 	// printf("helloeworld%n",&d);
// 	// c = ft_printf("helloeworld%n",&d);
// 	// int n  = printf("helloeworld%n",&d);
// 	// // printf("i = %d" , d);
// 	// ft_printf("i = %d" , d);
// 	// printf("%d\n",c);
// 	// printf("n:%d\n",n);

//     // c = printf("%+d\n", 1);
// 	// printf("%d\n",c);

//     // ft_printf("%+d\n", 1);
// 	// ft_printf("%d\n",a);

// 	// printf("-----------------answer1----------------\n");
// 	// ft_printf("set1:%p--------",p);
// 	// d = printf("set1:%pans\n",num);
// 	// printf("set1:%d\n",num);
// 	// d = printf(" %c %c %c ", '0', 0, '1');
//     // c  = printf(" %d ", -9);
//     // d = printf("%d ", num);
// 	// c = -123456;
// 	// d = printf("%x",-1);
// 	// d = printf("%x",-2);
// 	// d = printf("%x",-3);


//     // printf("%#o\n", 10);
//     // printf("%#o\n", 0);
//     // d = printf("%x\n", 10);
// 	// printf("%d\n",d);
//     // d = ft_printf("%x\n", 10);
// 	// printf("%d\n",d);
//     // d = printf("%#x\n", 10);
// 	// printf("%d\n",d);
//     // d = ft_printf("%#x\n", 10);
// 	// printf("%d\n",d);
//     // d = printf("%#x\n", 0);
// 	// printf("%d\n",d);
//     // d = ft_printf("%#x\n", 0);
// 	// // printf("%d\n",d);
// 	// printf("-------------------\n");
//     // printf("%X\n", 10);
//     // ft_printf("%X\n", 10);
//     // printf("%#X\n", 10);
//     // ft_printf("%#X\n", 10);
//     // printf("%#X\n", 0);
//     // ft_printf("%#X\n", 0);

// 	// printf("%d\n", 1);
// 	// printf("%d\n", 1);
// 	// printf("%d\n", -1);
// 	// printf("%d\n", -1);


// 	d = printf("% d\n", 1);
// 	printf("%d\n",d);
// 	d = ft_printf("% d\n", 1);
// 	printf("%d\n",d);

// 	printf("----------------------------\n");
// 	d = printf("% d\n", -1);
// 	d = ft_printf("% d\n", -1);

// 	// printf("%+d\n", 1);
// 	// printf("%+d\n", -1);
// 	// d = printf("%x",-4);
// 	// d = printf("%x",-16);
// 	// d = printf("%x",-17);
// 	// d = printf("%x",-18);
// 	// d = printf("%x",-19);
// 	// d = printf("%x",-20);
// 	// printf("%d",d);
// 	// printf("%d", d);

// 	// d = printf("%d\n", INT_MIN);
// 	// printf("%d", d);
// 	// // d = ft_printf(" %d ", num);

// 	// printf("d:%d", d);

// 	// d = printf(" %c %c %c ", '1', '2', '3');
// 	// printf("~~~~%X~~~~~\n",d);
// 	// printf("-----------------answer2----------------\n");
// 	// ft_printf("set1:%Xans",num);
// 	// d = ft_printf("%x", -9);
// 	// printf("%d",d);
// 	// d = -100;
// 	// ft_printf("%d", d);
// 	// ft_printf("d:%u", d);
//     // c  = ft_printf(" %d ", -9);
// 	// d = ft_printf("%d\n", INT_MIN);
// 	// printf("-----------------answer3----------------\n");
// 	// ft_printf("%d", d);
//     // d = ft_printf(" %u\n ", c);
//     // printf(" %d ",d);

// 	// d = ft_printf(" %c %c %c ", '1', '2', '3');
// 	// d = ft_printf("%c", '1');
// 	// ft_printf("%s",p);
// 	// printf("~~~~%X~~~~~\n",d);
// 	return (0);


// }



// // // void func(char *arg_1, ...) {
// // //     va_list ap;
// // //     va_start(ap, arg_1);
// // //     printf("arg_2: %d\n", va_arg(ap, int));
// // //     printf("arg_3: %lf\n", va_arg(ap, double));

// //     ~処理~

// }
// int main(void) {
//     char *arg_1 = "aaaaa";
// //     int arg_2 = 5;
// //     double arg_3 = 3.14;

// //     func(arg_1, arg_2, arg_3);
// // }