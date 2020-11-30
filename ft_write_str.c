//
// Created by Donny Roslyn on 12/1/20.
//
#include "libprintf.h"

void		ft_prn_str(char *str, t_options *opt)
{
	size_t	l;
	int		i;

	i = 0;
	if (!str)
	{
		if (!(str = ft_strdup(NULL_STR)))
			return ;
		ft_prn_str(str, opt);
		free(str);
		return ;
	}
	l = ft_strlen(str);
	if (opt->rigor == -1 && opt->width == -1)
	{
		opt->len = opt->len + write(1, str, l);
		return;
	}
	if (opt->rigor == -1 || opt->rigor > (int)l)
		opt->rigor = (int)l;
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
			while (opt->width-- > opt->rigor)    // наращиваем l, пока не достигнем нужной ширины
				opt->len = opt->len + write(1, " ", 1);
		}
		while (i < opt->rigor)
			opt->len = opt->len + write(1, &str[i++], 1);
	}
	return ;
}
