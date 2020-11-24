//
// Created by Кристина Смирнова on 21.11.2020.
//
#include <stdio.h>
#include "libprintf.h"

int     main()
{
    ft_printf("  %#34+*.*-");
    ft_printf(">>hello  |%0+20.0d", 0);
    printf("\n>>%0+20.0d", 0); //!!!!
    printf("--------------\n");
	ft_printf("|%.0d|\n", 0);
	printf("|%.0d|\n", 0);
	ft_printf("|%.d|\n", 0);
	printf("|%.d|\n", 0);
	ft_printf("|%5.d|\n", 0);
	printf("|%5.d|\n", 0);
	ft_printf("|%5.0d|\n", 0);
	printf("|%5.0d|\n", 0);
	ft_printf("|%-5.d|\n", 0);
	printf("|%-5.d|\n", 0);
}
