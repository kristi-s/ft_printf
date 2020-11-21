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

#include "libprintf.h"

void			ft_checkflag(char c, t_options *opt)
{
    if (c == '\0')
        return ;
    if (c == '-')
        opt->flag = opt->flag | FL_MINUS;
    else if (c == '+')
        opt->flag = opt->flag | FL_PLUS;
    else if (c == ' ')
        opt->flag = opt->flag | FL_SPACE;
    else if (c == '0')
        opt->flag = opt->flag | FL_NULL;
    else if (c == '#')
        opt->flag = opt->flag | FL_HESH;
}

int    ft_checkwdt(char *str, t_options *opt)
{
    int      width;
    int      i;

    i = 0;
    width = 1;
    if (ft_isdigit(*str) == 1)
    {
        width = ft_atoi(str);
        while (ft_isdigit(str[i]) == 1)
            i++;
    }
    else if (*str == '*')
        width = va_arg(opt->ap, int);
    opt->width = width;
    return (i);
}

int    ft_checkrigor(char *str, t_options *opt)
{
    int      rigor;
    int      i;

    i = 0;
    rigor = 1;
    if (ft_isdigit(*str) == 1)
    {
        rigor = ft_atoi(str);
        while (ft_isdigit(str[i]) == 1)
            i++;
    }
    else if (*str == '*')
    {
        rigor = va_arg(opt->ap, int);
        i = 1;
    }
    opt->rigor = rigor;
    return (i);
}
// 'cspdiuxX%'
void           ft_checktype(char c, t_options *opt)
{
    unsigned int    u_num;
    int             num;
    char            *str;

    if (ft_strchr("uxXp", c) == 1)
    {
        u_num = va_arg(opt->ap, unsigned int);
        ft_prn_uxx(u_num, opt);
    }
    else if (ft_strchr("di", c) == 1)
    {
        num = va_arg(opt->ap, int);
        ft_prn_di(num, opt);
    }
    else if (c == 's')
    {
        str = va_arg(opt->ap, char*);
        ft_prn_str(str, opt);
    }
    else
    {
        if (c == 'c')
            c = va_arg(opt->ap, char);
        ft_prn_char(c, opt);
    }
    return ;
}




/*
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
*/