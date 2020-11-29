//
// Created by Кристина Смирнова on 21.11.2020.
//
#define INT_MAX		2147483647
#define INT_MIN		-2147483648
#include <stdio.h>
#include "libprintf.h"

int     main() {
	int a;
	a = 10;
	int *p;
	p = &a;
//    ft_printf("  %#34+*.*-");
//    ft_printf(">>hello  |%0+20.0d", 0);
//    printf("\n>>%0+20.0d", 0); //!!!!
//    printf("--------------\n");
//    printf("|%30p|\n", p);
//	ft_printf("|%30p|\n", p);
//	printf("|%-30p|\n", p);
//	ft_printf("|%-30p|\n", p);
//	p = 0;
//	printf("|%30p|\n", p);
//	ft_printf("|%30p|\n", p);
//	printf("--------------\n");
	ft_printf("|%.p|\n", NULL);
	printf("|%.p|\n", NULL);
	ft_printf("|%.p|\n", &a);
	printf("|%.p|\n", &a);
	ft_printf("|%20.p|\n",NULL);
	printf("|%20.p|\n",NULL);
	ft_printf("|%20.p|\n", &a);
	printf("|%20.p|\n", &a);


}