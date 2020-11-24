//
// Created by Кристина Смирнова on 24.11.2020.
//
//сюда приходит только если точно есть флаги
#include "libprintf.h"

void			ft_write_int(int num, char *s, t_options *opt)
{
	size_t 	l;

	l = ft_strlen(s);
	if (l > opt->rigor)
		opt->rigor = l;
	if (num >= 0 && (opt->flag & FL_PLUS))
		ft_add_rigor_posit('+', l, s, opt);
	else if (num >= 0 && (opt->flag & FL_SPACE))
		ft_add_rigor_posit(' ', l, s, opt);
	else if (num >= 0)
		ft_add_rigor_posit('?', l, s, opt);
	else if (num < 0)
		ft_add_rigor_posit('-', l, (s + 1), opt);


}

//для положительных чисел
void 		ft_add_rigor_posit(char c, size_t l, char *s, t_options opt)
{
	int 	i;

	i = 0;
	if (!(opt->flag & FL_MINUS)) // напечатает если
	{
		if ((c == '+' || c == ' ' || c == '-'))
			i = 1;
		while ((opt->rigor + i++ ) < opt->width)
			opt->len = opt->len + write(1, " ", 1);
	}
	if (c == '+' || c == ' ' || c == '-')
		opt->len = opt->len + write(1, &c, 1);
	while (l++ < opt->rigor)
		opt->len = opt->len + write(1, "0", 1);
	opt->len = opt->len + write(1, s, ft_strlen(s));
	if (c == '+' || c == ' ')
		l++;
	if (opt->flag & FL_MINUS)
	{
		while (l++ < opt->width)
			opt->len = opt->len + write(1, " ", 1);
	}
	return ;
}