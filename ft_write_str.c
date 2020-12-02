/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droslyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:46:05 by droslyn           #+#    #+#             */
/*   Updated: 2020/12/02 18:13:08 by droslyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

static void		ft_write_str(int i, char *str, t_options *opt)
{
	if (opt->flag & FL_MINUS)
	{
		while (i < opt->rigor)
			opt->len = opt->len + write(1, &str[i++], 1);
		if (opt->width != -1)
		{
			while (i++ < opt->width)
				opt->len = opt->len + write(1, " ", 1);
		}
	}
	else
	{
		if (opt->width != -1)
		{
			while (opt->width-- > opt->rigor)
				opt->len = opt->len + write(1, " ", 1);
		}
		while (i < opt->rigor)
			opt->len = opt->len + write(1, &str[i++], 1);
	}
	return ;
}

void			ft_prn_str(char *str, t_options *opt)
{
	int			l;
	int			i;

	i = 0;
	if (!str)
	{
		if (!(str = ft_strdup(NULL_STR)))
			return ;
		ft_prn_str(str, opt);
		free(str);
		return ;
	}
	l = (int)ft_strlen(str);
	if (opt->rigor == -1 && opt->width == -1)
	{
		opt->len = opt->len + write(1, str, l);
		return ;
	}
	if (opt->rigor == -1 || opt->rigor > l)
		opt->rigor = l;
	ft_write_str(i, str, opt);
	return ;
}
