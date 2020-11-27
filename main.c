//
// Created by Кристина Смирнова on 21.11.2020.
//
#include <stdio.h>
#include "libprintf.h"

int     main()
{
//    ft_printf("  %#34+*.*-");
//    ft_printf(">>hello  |%0+20.0d", 0);
//    printf("\n>>%0+20.0d", 0); //!!!!
//    printf("--------------\n");
//	ft_printf("|%.10u|\n", 4294967295);
//	printf("|%.10u|\n", 4294967295);
//	ft_printf("|%.10u|\n", 123456);
//	printf("|%.10u|\n", 123456);
//	ft_printf("|%15.10u|\n", 123456);
//	printf("|%15.10u|\n", 123456);
	ft_printf("|%#15x|\n", 123456);
	printf("|%#15x|\n", 123456);
	ft_printf("|%-#15x|\n", 4294967295);
	printf("|%-#15x|\n", 4294967295);
}
