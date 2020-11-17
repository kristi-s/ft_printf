/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droslyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 20:42:12 by droslyn           #+#    #+#             */
/*   Updated: 2020/11/17 23:11:28 by droslyn          ###   ########.fr       */
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
			format_str = format_str + ft_checkflag(format_str + 1);
		format_str++;
		
	}

	va_end(ap);
	return (len); //len - count chars were printed 
}

// возвращает число на сколько нужно сдвинуть указатель
// н-р: '*.0d' вернет 4, тк за сдвиг на '%' отвечает прирощение в цикле
//
int			ft_checkflag(char *str)
{
	char	*flag;
	int		n;
	int		wdt;
	int		rigor;
	
	n = 0;
	if (*str == '\0')
		return (0);
	while (str[n] != '0' && ft_strchr("-0.*123456789", str[n]))
	{
		if (str[n] == '*')
			//запросить значение
		n++;
	}
}

//
//КАК СЧИТАТЬ РАЗМЕР НАПЕЧАТАННОГО?????
//
//
/******************************/
// if (*format_str == '%') // t.e. '%%'
//		ft_putchar_fd('%', 1);
//		len++;
//****************************/
// if (*format_str == 'd') // t.e. '%d'
// 		int num = va_arg(ap, int);
// 		char *s = ft_itoa(num);
// 		len = len + ft_strlen(s);
// 		ft_putstr_fd(s, 1);
// 		free(s);
//
// 		по умолчанию точность 1
// 		при 0 точности если num = 0, то ничего не печатаем
//****************************/
// if (*format_str == 'i') // t.e. '%i'
// 		int num = va_arg(ap, int);
// 		char *s = ft_itoa(num);
// 		len = len + ft_strlen(s);
// 		ft_putstr_fd(s, 1);
// 		free(s);
//
// 		по умолчанию точность 1
// 		при 0 точности если num = 0, то ничего не печатаем
//****************************/
// if (*format_str == 'u') // t.e. '%u'
// 		unsigned int num = va_arg(ap, unsigned int);
// 		char *s = ft_itoa(num); // изменить под uns int
// 		len = len + ft_strlen(s);
// 		ft_putstr_fd(s, 1); // изменить под uns int
// 		free(s);
//
// 		по умолчанию точность 1
// 		при 0 точности если num = 0, то ничего не печатаем
//****************************/
// if (*format_str == 'x') // t.e. '%x'
// 		int num = va_arg(ap, unsigned int);
// 		char *s = // функция которая преобразует uns int в строку 
// 		шестнадцатиричного формата типо putnbr_base16 ('0123456789abcdef')
// 		len = len + ft_strlen(s);
// 		ft_putstr_fd(s, 1);
// 		free(s);
//
// 		по умолчанию точность 1
// 		при 0 точности если num = 0, то ничего не печатаем
//****************************/
// if (*format_str == 'X') // t.e. '%X'
// 		int num = va_arg(ap, unsigned int);
// 		char *s = // функция которая преобразует uns int в строку 
// 		шестнадцатиричного формата типо putnbr_base16 ('0123456789ABCDEF')
// 		len = len + ft_strlen(s);
// 		ft_putstr_fd(s, 1);
// 		free(s);
//
// 		по умолчанию точность 1
// 		при 0 точности если num = 0, то ничего не печатаем
//****************************/
// if (*format_str == 'c') // t.e. '%c'
// 		unsigned char ch = (unsigned char)va_arg(ap, int); 
// 		ft_putchar_fd(ch, 1);
//		len++;
//****************************/
// if (*format_str == 's') // t.e. '%s'
// 		char *s = va_arg(ap, char *);
// 		len = len + ft_strlen(s);
// 		ft_putstr_fd(s, 1);
//***************************/
//

