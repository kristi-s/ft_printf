#include "libprintf.h"
// написать отдельную функцию для u - ДЕСЯТИЧНОЕ беззнаковое!!!!
void			ft_prn_un_int(unsigned int u_num, t_options *opt)
{
	char 	*s;
	size_t 	l;

	// сделать отдельный itoa? так тоже влезет
	s = ft_itoa_hex("0123456789", u_num, 10, opt);
	if (opt->flag == 0 && opt->rigor == -1) // нет флагов и точности.
	{
		ft_prn_str(s, opt);
		free(s);
		return ;
	}
	l = ft_strlen(s);
	if (opt->rigor != -1 && (opt->flag & FL_NULL))
		opt->flag = opt->flag - FL_NULL;
	if ((l > opt->rigor) && (opt->rigor != 0))
		opt->rigor = l;
	if (opt->flag & FL_PLUS)
		ft_add_rigor_posit('+', l, s, opt);
	else if (opt->flag & FL_SPACE)
		ft_add_rigor_posit(' ', l, s, opt);
	else if (u_num > 0)
		ft_add_rigor_posit('?', l, s, opt);
	else if (u_num == 0)
		ft_add_rigor_posit('?', 0, s, opt);

	free(s);
	return ;
}

void          ft_prn_uxx(unsigned int u_num, t_options *opt)
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
	if (opt->rigor != -1 && (opt->flag & FL_NULL))
		opt->flag = opt->flag - FL_NULL;
	if ((l > opt->rigor) && (opt->rigor != 0))
		opt->rigor = l;
	ft_add_rigor_hex(l, s, opt);


	free(s);
	return ;
    // превращать в строку, считать длину цифр и добавлять при необходимости знак и доп до ширины
    //opt->len = opt->len + l;//печетать в зависимости от опций и записывать длину напечатанного.
}
// флаг '+' и ' ' используются только для десятичных чисел
void           ft_prn_di(int num, t_options *opt)
{
    int     l;
    char 	*s;

    s = ft_itoa(num);
    l = ft_strlen(s);

	if (opt->flag == 0 && opt->rigor == -1) // нет флагов и точности.
	{
		ft_prn_str(s, opt);
		free(s);
		return ;
	}
	if (opt->rigor != -1 && (opt->flag & FL_NULL))
		opt->flag = opt->flag - FL_NULL; //флаг нул игнорируется, если указана точность
//	если ригор -1, есть флаг нул и ширина - то ширину приравнивать в ригор
	if (opt->rigor == -1 && (opt->flag & FL_NULL) && opt->width > 0 && num < 0)
		opt->rigor = opt->width - 1;
	if ((l > opt->rigor) && (num >= 0) && (opt->rigor != 0))
		opt->rigor = l;
	if (num < 0 && (l - 1 > opt->rigor))
		opt->rigor = l - 1;
	if (num >= 0 && (opt->flag & FL_PLUS))
		ft_add_rigor_posit('+', l, s, opt);
	else if (num >= 0 && (opt->flag & FL_SPACE))
		ft_add_rigor_posit(' ', l, s, opt);
	else if (num > 0)
		ft_add_rigor_posit('?', l, s, opt);
	else if (num == 0)
		ft_add_rigor_posit('?', 0, s, opt);
	else if (num < 0)
		ft_add_rigor_posit('-', l - 1, (s + 1), opt);
	free(s);
	return ;
}
// флаг нул не применим для %s это ub
void           ft_prn_str(char *str, t_options *opt)
{
    size_t    l;
    int     i;

    i = 0;
    l = ft_strlen(str);
    if (opt->rigor > 0 && opt->rigor > l)
    {
        l = opt->rigor;
        str[l] = '\0';
    }
    if (opt->width > 0 && opt->width > l) {
        if (opt->flag & FL_MINUS)
        {
            opt->len = opt->len + write(1, str, l);
            while (l++ < opt->width)    // наращиваем l, пока не достигнем нужной ширины
                opt->len = opt->len + write(1, " ", 1); // на каждой итерации печатаем space
        } // нужен ли ретурн???
        else if (opt->flag & FL_NULL)
        {
            while (l + i++ < opt->width)    // можно уменьшать (opt->width--) и убрать i
                opt->len = opt->len + write(1, "0", 1); // на каждой итерации печатаем ноль
            opt->len = opt->len + write(1, str, l);    //после нулей печатаем строку нужной длины
        }
        else
		{
			while (l++ < opt->width)    // наращиваем l, пока не достигнем нужной ширины
				opt->len = opt->len + write(1, " ", 1);
			opt->len = opt->len + write(1, str, ft_strlen(str));
		}
    }
    else
        opt->len = opt->len + write(1, str, l);
	return ;
}

// флаг нул не применим для %c это ub
void            ft_prn_char(unsigned char c, t_options *opt)
{
    int     l;

    l = 1; // начинаем с 1, тк с занимает знак.
    if (opt->width > 1)
	{
		if (opt->flag & FL_MINUS)
		{
			opt->len = opt->len + write(1, &c, 1);
			while (l++ < opt->width)    // наращиваем l, пока не достигнем нужной ширины
				opt->len = opt->len + write(1, " ", 1); // на каждой итерации печатаем space
		}
		else if (opt->flag & FL_NULL)
		{
			while (l++ < opt->width)
				opt->len = opt->len + write(1, "0", 1); // на каждой итерации печатаем ноль
			opt->len = opt->len + write(1, &c, 1);    //после нулей печатаем строку нужной длины
		}
	}
    else
		opt->len = opt->len + write(1, &c, 1);
    return ;
}

