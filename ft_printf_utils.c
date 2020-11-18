/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droslyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 14:50:00 by droslyn           #+#    #+#             */
/*   Updated: 2020/11/18 17:08:10 by droslyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libprintf.h"


// как обрабатывать rigor с char???
//
//-------------CHAR-------------------------------//
//left align 
void		ft_l_alg_chr(int c, int wdt, int rigor)
{
	ft_putchar_fd((char)c, 0);
	while (wdt > 1)
	{
		ft_putchar_fd(' ', 0);
		wdt--;
	}	
	return ;
}

// right align
void		ft_r_alg_chr(int c, int wdt, int rigor)
{
	while (wdt > 1)
	{
		ft_putchar_fd(' ', 0);
		wdt--;
	}	
	ft_putchar_fd((char)c, 0);
	return ;
}

//rigth align with '0'
void		ft_null_alg_chr(int c, int wdt, int rigor)
{
	while (wdt > 1)
	{
		ft_putchar_fd('0', 0);
		wdt--;
	}	
	ft_putchar_fd((char)c, 0);
	return ;
}

//--------------------STRING-----------------------//

//left align
void		ft_l_alg_str(char *s1, wdt, rigor)
{
	
}
