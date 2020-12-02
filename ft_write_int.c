/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droslyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 17:29:47 by droslyn           #+#    #+#             */
/*   Updated: 2020/12/01 18:24:33 by droslyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

static void		ft_write_int(char c, int l, char *s, t_options *opt)
{
	int			i;
	char		c0;

	i = 0;
	if (!(opt->flag & FL_MINUS))
	{
		if ((c == '+' || c == ' ' || c == '-'))
			i = 1;
		if (opt->flag & FL_NULL)
			c0 = '0';
		else
			c0 = ' ';
		while ((opt->width != -1) && ((opt->rigor + i++) < opt->width))
			opt->len = opt->len + write(1, &c0, 1);
	}
	if (c == '+' || c == ' ' || c == '-')
		opt->len = opt->len + write(1, &c, 1);
	while (l++ < opt->rigor)
		opt->len = opt->len + write(1, "0", 1);
	if (s[0] != '0' || opt->rigor != 0)
		opt->len = opt->len + write(1, s, ft_strlen(s));
	if (!(c == '+' || c == ' ' || c == '-'))
		l--;
	while ((opt->flag & FL_MINUS) && (opt->width != -1) && (l++ < opt->width))
		opt->len = opt->len + write(1, " ", 1);
}

static void		ft_switch(long long num, int l, char *s, t_options *opt)
{
	if (num >= 0 && (opt->flag & FL_PLUS))
		ft_write_int('+', l, s, opt);
	else if (num >= 0 && (opt->flag & FL_SPACE))
		ft_write_int(' ', l, s, opt);
	else if (num > 0)
		ft_write_int('?', l, s, opt);
	else if (num == 0)
		ft_write_int('?', l, s, opt);
	else if (num < 0)
		ft_write_int('-', l - 1, (s + 1), opt);
}

void			ft_prn_di(int num, t_options *opt)
{
	int			l;
	char		*s;

	s = ft_itoa(num);
	l = (int)ft_strlen(s);
	if (opt->flag <= 1 && opt->rigor == -1)
	{
		ft_prn_str(s, opt);
		free(s);
		return ;
	}
	if (opt->rigor != -1 && (opt->flag & FL_NULL))
		opt->flag = opt->flag - FL_NULL;
	if (opt->rigor == -1 && (opt->flag & FL_NULL) && !(opt->flag & FL_MINUS) &&
			opt->width > 1)
		opt->rigor = opt->width - 1;
	if ((l > opt->rigor) && (num >= 0) && (opt->rigor != 0 || num != 0))
		opt->rigor = l;
	if (num < 0 && (l - 1 > opt->rigor))
		opt->rigor = l - 1;
	if (num == 0 && opt->rigor == 0)
		l = 0;
	ft_switch(num, l, s, opt);
	free(s);
}

void			ft_prn_un_int(unsigned int u_num, t_options *opt)
{
	char		*s;
	int			l;

	s = ft_itoa_hex("0123456789", u_num, 10, opt);
	if (opt->flag <= 1 && opt->rigor == -1)
	{
		ft_prn_str(s, opt);
		free(s);
		return ;
	}
	l = (int)ft_strlen(s);
	if (opt->rigor != -1 && (opt->flag & FL_NULL))
		opt->flag = opt->flag - FL_NULL;
	if (opt->rigor == -1 || ((l > opt->rigor) && (opt->rigor != 0 ||
			u_num != 0)))
		opt->rigor = l;
	if (u_num == 0 && opt->rigor == 0)
		l = 0;
	ft_switch(u_num, l, s, opt);
	free(s);
}
