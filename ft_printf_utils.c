/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droslyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 14:50:00 by droslyn           #+#    #+#             */
/*   Updated: 2020/12/01 00:10:31 by droslyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

void		ft_checkflag(char c, t_options *opt)
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

static int	ft_abs(int n)
{
	if (n >= 0)
		return (n);
	else
		return (-n);
}

int			ft_checkwdt(char *str, t_options *opt)
{
	int		width;
	int		i;

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
	opt->width = ft_abs(width);
	if (width < 0)
	{
		opt->flag = opt->flag | FL_MINUS;
		if (opt->flag & FL_NULL)
			opt->flag = opt->flag - FL_NULL;
	}
	return (i);
}

int			ft_checkrigor(char *str, t_options *opt)
{
	int		rigor;
	int		i;

	i = 0;
	rigor = 0;
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
	if (rigor >= 0)
		opt->rigor = rigor;
	return (i);
}

void		ft_checktype(t_options *opt)
{
	if (ft_strchr("uxX", opt->spcf) != NULL)
		ft_prn_uxx(va_arg(opt->ap, unsigned int), opt);
	else if (opt->spcf == 'p')
		ft_prn_ptr(va_arg(opt->ap, unsigned long long), opt);
	else if (ft_strchr("di", opt->spcf) != NULL)
		ft_prn_di(va_arg(opt->ap, int), opt);
	else if (opt->spcf == 's')
		ft_prn_str(va_arg(opt->ap, char*), opt);
	else
	{
		if (opt->spcf == 'c')
			opt->spcf = (unsigned char)va_arg(opt->ap, int);
		ft_prn_char((unsigned char)opt->spcf, opt);
	}
}
