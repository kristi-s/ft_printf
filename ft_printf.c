/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droslyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 20:42:12 by droslyn           #+#    #+#             */
/*   Updated: 2020/11/18 17:08:18 by droslyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libprintf.h"

#define FL_NON      0b00000000
#define FL_MINUS    0b00000001
#define FL_PLUS     0b00000010
#define FL_SPACE    0b00000100
#define FL_HESH     0b00001000
#define FL_NULL     0b00010000

int				ft_printf(const char *format_str, ...)
{
	va_list		ap;
	unsigned char fl=0; // delete!!!

	if (!format_str)
		return (0);
	va_start(ap, format_str);
	while (*format_str)
	{
		if (*format_str != '%')
			ft_putchar_fd(*format_str, 1);
		else {
            format_str = format_str + ft_checkflag(format_str + 1, &fl);
            ft_putchar_fd(fl, 1);
        }
		format_str++;

	}

	va_end(ap);
	return (0); //len - count chars were printed
}

// возвращает число на сколько нужно сдвинуть указатель
// н-р: '*.0d' вернет 4, тк за сдвиг на '%' отвечает прирощение в цикле
// возможные флаги "-+ #0"
//
//на вход приходит указатель на след символ после '%'
int			ft_checkflag(char *str, unsigned char *f)
{
	unsigned char	flag;
	int		n;

	flag = FL_NON;
	n = 0;
	if (*str == '\0')
		return (0);
	while (str[n] != '\0' && ft_strchr("-0.*123456789+ #", str[n]))
	{
		if (str[n] == '-')
		    flag = flag | FL_MINUS;
        else if (str[n] == '+')
            flag = flag | FL_PLUS;
        else if (str[n] == ' ')
            flag = flag | FL_SPACE;
        else if (str[n] == '0')
            flag = flag | FL_NULL;
        else if (str[n] == '#')
            flag = flag | FL_HESH;
		n++;
	}
	*f = flag; //delete!!!! изменить прототип!!! удалить отладочные перем
	return (n);
}

// далее вызвать функцию которая распределяет на печать в зависимости от типа 'dixcsX'
// внутри вызывать функцию которая парсит ширину и точность (можно сдалать как две отдельных функции)
// как возвращать размер напечатанного??? передавать переменную по адресу?
/*
void		ft_align(char *str, int n, int wdt, int rigor)
{
	int		i;

	i = 0;
	while (i < n)
	{
		if (str[i] == '-')
		{
			ft_left_align((str + n), wdt, rigor);
			return ;
		}
		i++;
	}
	i = 0;
	while (i < n)
	{
		if (ft_isdigit(str[i]) == 1)
		{
			if (str[i] == '0')
			{
				ft_null_align((str + n), wdt, rigor);
				return ;
			}
			i = n;
		}
		i++;
	}
	ft_right_align((str + n), wdt, rigor);
	return ;
}

void		ft_right_align(char *str, int wdt, int rigor)
{
	char 			*s1;
	int				c;
	unsigned int	num;
	unsigned long long	hex_num;

	if (*str == 's')
	{
		s1 = va_arg(ap, char *);
		ft_r_alg_str(s1, wdt, rigor);
		return ;	
	}
	else if (*str == 'c')
	{
		c = va_arg(ap, int);
		ft_r_alg_chr(c, wdt, rigor);
		return ;	
	}
	else if (*str == 'd' || *str == 'i')
	{
		num = va_arg(ap, unsigneg int);
		ft_r_alg_int(num, wdt, rigor);
		return ;
	}
	else if (*str == 'x' || *str == 'X' || *str == 'p')
	{
		num = va_arg(ap, unsigneg int);
		ft_r_alg_hex(hex_num, wdt, rigor);
		return ;
	}
	else if (*str == 'p')
	{
		hex_num = va_arg(ap, unsigneg long long);
		ft_r_alg_ptr(hex_num, wdt, rigor);
		return ;
	}
	else 
	{
		ft_r_alg_chr((int)*str, wdt, rigor);
		return ;
	}
}
*/

//
//можно сначала отделить всё обозначение '%...'
//потом отправлять на парсиинг и получать возврат wdt, rigor??
//
//
//
//КАК СЧИТАТЬ РАЗМЕР НАПЕЧАТАННОГО?????
//переменная внутри страктуры?
//переменная выделенная malloc?
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

