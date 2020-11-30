/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droslyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 19:09:25 by droslyn           #+#    #+#             */
/*   Updated: 2020/11/30 19:16:01 by droslyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

void		ft_prn_un_int(unsigned int u_num, t_options *opt)
{
	char 	*s;
	size_t 	l;

	s = ft_itoa_hex("0123456789", u_num, 10, opt);
	if (opt->flag <= 1 && opt->rigor == -1)
	{
		ft_prn_str(s, opt);
		free(s);
		return ;
	}
	l = ft_strlen(s);
	if (opt->rigor != -1 && (opt->flag & FL_NULL))
		opt->flag = opt->flag - FL_NULL;
	if (opt->rigor == -1 || (((int)l > opt->rigor) && (opt->rigor != 0)))
		opt->rigor = l;
	if (u_num == 0 && opt->rigor == 0)
		l = 0;
	if (opt->flag & FL_PLUS)
		ft_add_rigor_posit('+', l, s, opt);
	else if (opt->flag & FL_SPACE)
		ft_add_rigor_posit(' ', l, s, opt);
	else if (u_num > 0)
		ft_add_rigor_posit('?', l, s, opt);
	else if (u_num == 0)
		ft_add_rigor_posit('?', l, s, opt);
	free(s);
	return ;
}

void		ft_prn_uxx(unsigned int u_num, t_options *opt)
{
    int     l;
	char 	*s;

	if (opt->spcf == 'X')
		s = ft_itoa_hex(BASE_BIG, u_num, SIZE_BASE, opt);
	else if (opt->spcf == 'x')
		s = ft_itoa_hex(BASE_SMALL, u_num, SIZE_BASE, opt);
	else if (opt->spcf == 'u')
		return (ft_prn_un_int(u_num, opt));
	if ((opt->flag == 0 || opt->flag - FL_HESH == 0) && opt->rigor == -1) // нет флагов и точности.
	{
		ft_prn_str(s, opt);
		free(s);
		return ;
	}
	l = ft_strlen(s);
	if (u_num == 0 && (opt->flag & FL_HESH))
		opt->flag = opt->flag - FL_HESH;
	if (opt->rigor != -1 && (opt->flag & FL_NULL))
		opt->flag = opt->flag - FL_NULL;
	if ((opt->flag & FL_NULL) && opt->rigor == -1 && opt->width > 0)
		opt->rigor = (opt->flag & FL_HESH) ? (opt->width - 2) : opt->width;
	if ((opt->flag & FL_HESH) && opt->rigor + 2 > l)
		opt->rigor = opt->rigor + 2;
	else if (((l > opt->rigor) && (opt->rigor != 0)) || opt->rigor == -1)
		opt->rigor = l;
	if (opt->rigor == 0 && u_num == 0)
		ft_add_rigor_hex(u_num, 0, s, opt);
	else
		ft_add_rigor_hex(u_num, l, s, opt);
	free(s);
	return ;
}



void		ft_prn_di(int num, t_options *opt)
{
    int     l;
    char 	*s;

    s = ft_itoa(num);
    l = ft_strlen(s);

	if (opt->flag <= 1 && opt->rigor == -1)
	{
		ft_prn_str(s, opt);
		free(s);
		return ;
	}
	if (opt->rigor != -1 && (opt->flag & FL_NULL))
		opt->flag = opt->flag - FL_NULL;
	if (opt->rigor == -1 && (opt->flag & FL_NULL) && !(opt->flag & FL_MINUS) && opt->width > 0) //&& num < 0)
		opt->rigor = opt->width - 1;
	if ((l > opt->rigor) && (num >= 0) && (opt->rigor != 0))
	opt->rigor = l;
	if (num < 0 && (l - 1 > opt->rigor))
		opt->rigor = l - 1;
	if (num == 0 && opt->rigor == 0)
		l = 0;
	if (num >= 0 && (opt->flag & FL_PLUS))
		ft_add_rigor_posit('+', l, s, opt);
	else if (num >= 0 && (opt->flag & FL_SPACE))
		ft_add_rigor_posit(' ', l, s, opt);
	else if (num > 0)
		ft_add_rigor_posit('?', l, s, opt);
	else if (num == 0)
		ft_add_rigor_posit('?', l, s, opt);
	else if (num < 0)
		ft_add_rigor_posit('-', l - 1, (s + 1), opt);
	free(s);
	return ;
}



void            ft_prn_char(unsigned char c, t_options *opt)
{
    int     l;

    l = 1;
    if (opt->width > 1)
	{
		if (opt->flag & FL_MINUS)
		{
			opt->len = opt->len + write(1, &c, 1);
			while (l++ < opt->width)
				opt->len = opt->len + write(1, " ", 1);
		}
		else if (opt->flag & FL_NULL)
		{
			while (l++ < opt->width)
				opt->len = opt->len + write(1, "0", 1);
			opt->len = opt->len + write(1, &c, 1);
		}
		else
		{
			while (l++ < opt->width)
				opt->len = opt->len + write(1, " ", 1);
			opt->len = opt->len + write(1, &c, 1);
		}
	}
    else
		opt->len = opt->len + write(1, &c, 1);
    return ;
}

