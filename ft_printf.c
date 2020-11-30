/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droslyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 20:42:12 by droslyn           #+#    #+#             */
/*   Updated: 2020/11/30 23:19:19 by droslyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

int				ft_printf(const char *format_str, ...)
{
	t_options	*opt;
	int			i;

	if (!format_str || !(opt = (t_options *)malloc(sizeof(t_options))))
		return (0);
	va_start(opt->ap, format_str);
	opt->len = 0;
	i = 0;
	while (format_str[i])
	{
		if (format_str[i] != '%')
			opt->len = opt->len + write(1, &format_str[i], 1);
		else
			i = i + ft_checkopt((char *)format_str + i + 1, opt);
		if (format_str[i] != '\0')
			i++;
	}
	va_end(opt->ap);
	i = opt->len;
	free(opt);
	return (i);
}

int				ft_checkopt(char *str, t_options *opt)
{
	int			n;

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
		return (n);
	opt->spcf = str[n];
	ft_checktype(opt);
	return (n + 1);
}
