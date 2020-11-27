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



int				ft_printf(const char *format_str, ...)
{
	t_options   *opt;
	int         i;

	if (!format_str || !(opt = (t_options *)malloc(sizeof(t_options))))
		return (0);
	va_start(opt->ap, format_str);
	opt->len = 0;
	i = 0;
	while (format_str[i])
	{
		if (format_str[i] != '%')
            opt->len = opt->len + write(1, &format_str[i], 1);
		else {
            i = i + ft_checkopt((char *)format_str + i + 1, opt);
            //ft_putchar_fd(fl, 1); //для отладки как записался флаг
        }
		if (format_str[i] != '\0')
			i++;
	}
	va_end(opt->ap);
	i = opt->len;
	free(opt);
	return (i); //len - count chars were printed
}

int         ft_checkopt(char *str, t_options *opt)
{
    int     n;

    n = 0;
    opt->flag = FL_NON;
    opt->width = -1;
    opt->rigor = -1;
    while (str[n] != '\0' && ft_strchr("-0.*123456789+ #", str[n]))
    {
        if (str[n] == '-' || str[n] == '+' || str[n] == ' ' || str[n] == '0'
            || str[n] == '#')
            ft_checkflag(str[n], opt);
        else if (ft_isdigit(str[n]) == 1)
            n = n + ft_checkwdt((str + n), opt) - 1;
        else if (str[n] == '*')
            ft_checkwdt((str + n), opt);
        else if (str[n] == '.')
            n = n + ft_checkrigor((str + n + 1), opt);
        n++;
    }
    if (str[n] == '\0')
        return (n); // ничего не делать, если достигли конца строки, значит далее нет типа
	opt->spcf = str[n];
	ft_checktype(opt);     // тк n элемент это тип и его тоже нужно пролистнуть в следующей строке
    return (n + 1);
}
// возвращает число на сколько нужно сдвинуть указатель
// н-р: '*.0d' вернет 4, тк за сдвиг на '%' отвечает прирощение в цикле
// возможные флаги "-+ #0"
//
//на вход приходит указатель на след символ после '%'


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

