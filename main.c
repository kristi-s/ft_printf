//
// Created by Кристина Смирнова on 21.11.2020.
//
#define INT_MAX		2147483647
#define INT_MIN		-2147483648
#include <stdio.h>
//#include <limits.h>
#include "libprintf.h"

int     main() {
	unsigned int x = 0;

	ft_printf("-->|%0*.x|<--\n", 2, x);
	ft_printf("-->|%0*.x|<--\n", 3, x);
	ft_printf("-->|%0*.x|<--\n", 4, x);
	ft_printf("-->|%0*x|<--\n", -4, x);
	ft_printf("-->|%0*x|<--\n", -4, x);
	printf("-------------\n");
	printf("-->|%0*.x|<--\n", 2, x);
	printf("-->|%0*.x|<--\n", 3, x);
	printf("-->|%0*.x|<--\n", 4, x);
	printf("-->|%0*x|<--\n", -4, x);
	printf("-->|%0*x|<--\n", -4, x);
}