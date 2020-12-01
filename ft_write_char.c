/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droslyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:51:16 by droslyn           #+#    #+#             */
/*   Updated: 2020/12/01 16:55:07 by droslyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

void		ft_prn_char(unsigned char c, t_options *opt)
{
	int		l;

	l = 1;
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
