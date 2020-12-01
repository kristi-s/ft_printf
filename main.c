//
// Created by Кристина Смирнова on 21.11.2020.
//
#define INT_MAX		2147483647
#define INT_MIN		-2147483648
#include <stdio.h>
#include "libprintf.h"

int     main() {
	int a = 0;
	int b = 0;

	a = printf("|%-10c|\n", 'A');
	b = ft_printf("|%-10c|\n", 'A');
	printf("a = %d, b = %d\n", a, b);
//
//	int *p;
//	p = &a;
//	a = printf("%#05x\n", 43);
//	b = ft_printf("%#05x\n", 43);
//	printf("a = %d, b = %d\n", a, b);
//
//	b = ft_printf(">>hello  |%0+20.0d", 0);
//	a = printf(">>hello  |%0+20.0d", 0);
//	printf("a = %d, b = %d\n", a, b);
//    a = ft_printf(">>hello  |%0+20.0d", 0);
//    printf("\na = %d\n", a);
//	a = printf(">>hello  |%0+20.0d", 0);
//	printf("\na = %d\n", a);
//    printf("\n>>%0+20.0d", 0); //!!!!
//    printf("--------------\n");
//    a = printf("|%30p|\n", p);
//	printf("\na = %d\n", a);
//	b = ft_printf("|%30p|\n", p);
//	printf("\nb = %d\n", b);
//	a = printf("|%-30p|\n", p);
//	printf("\na = %d\n", a);
//	b = ft_printf("|%-30p|\n", p);
//	printf("\nb = %d\n", b);

//	p = 0;
//	printf("|%30p|\n", p);
//	ft_printf("|%30p|\n", p);
//	printf("--------------\n");
//	ft_printf("|%.p|\n", NULL);
//	printf("|%.p|\n", NULL);
//	ft_printf("|%.p|\n", &a);
//	printf("|%.p|\n", &a);
//	ft_printf("|%20.p|\n",NULL);
//	printf("|%20.p|\n",NULL);
//	ft_printf("|%20.p|\n", &a);
//	printf("|%20.p|\n", &a);

	b = ft_printf("|%s%d%p%%%i%u%x%X%c|\n","bonjour", 42, &a, 42, 42, 42, 42, 'c');
	a = printf("|%s%d%p%%%i%u%x%X%c|\n","bonjour", 42, &a, 42, 42, 42, 42, 'c');
	printf("a = %d, b = %d\n", a, b);
}