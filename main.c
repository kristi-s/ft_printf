//
// Created by Кристина Смирнова on 21.11.2020.
//
#define INT_MAX		2147483647
#define INT_MIN		-2147483648
#include <stdio.h>
#include "libprintf.h"

int     main() {
    ft_printf("  %#34+*.*-");
    ft_printf(">>hello  |%0+20.0d", 0);
    printf("\n>>%0+20.0d", 0); //!!!!
    printf("--------------\n");


}