/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droslyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 20:42:12 by droslyn           #+#    #+#             */
/*   Updated: 2020/11/16 23:43:47 by droslyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libprintf.h"

int				ft_printf(const char *format_str, ...)
{
	va_list		ap;

	if (!format_str)
		return (0);
	va_start(ap, format_str);
	while (format_str)
	{
		if (*format_str != '%')
			ft_putchar(*format_str, 1);
		else
			ft_parsflag(format_str);
		
	}

	va_end(ap);
	return (len); //len - count chars were printed 
}
