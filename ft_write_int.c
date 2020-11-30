//
// Created by Кристина Смирнова on 24.11.2020.
//
//сюда приходит только если точно есть флаги
#include "libprintf.h"



//для всех чисел
void 		ft_add_rigor_posit(char c, size_t l, char *s, t_options *opt)
{
	int 	i;
	char	c0;

	i = 0;
	if (!(opt->flag & FL_MINUS)) // напечатает если
	{
		if ((c == '+' || c == ' ' || c == '-'))
			i = 1;
		if (opt->flag & FL_NULL) //&& s[0] != '0')
			c0 = '0';
		else
			c0 = ' ';
		while ((opt->width != -1) && ((opt->rigor + i++) < opt->width))
			opt->len = opt->len + write(1, &c0, 1);
	}
	if (c == '+' || c == ' ' || c == '-')
		opt->len = opt->len + write(1, &c, 1);
	while ((int)l++ < opt->rigor)	//наращивается l на 1 в любом случае
		opt->len = opt->len + write(1, "0", 1);
	if (s[0] != '0' || opt->rigor != 0)
		opt->len = opt->len + write(1, s, ft_strlen(s));
	if (!(c == '+' || c == ' '|| c == '-'))
		l--;
	while ((opt->flag & FL_MINUS) && (opt->width != -1) && ((int)l++ < opt->width))
		opt->len = opt->len + write(1, " ", 1);
	return ;
}