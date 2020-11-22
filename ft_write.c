#include "libprintf.h"

void          ft_prn_uxx(unsigned int u_num, t_options *opt)
{
    int     l;
    l = 0;
    // превращать в строку, считать длину цифр и добавлять при необходимости знак и доп до ширины
    //opt->len = opt->len + l;//печетать в зависимости от опций и записывать длину напечатанного.
}

void           ft_prn_di(int num, t_options *opt)
{
    int     l;
    char 	*s;

    s = ft_itoa(num);
    l = ft_strlen(s);
    if (num == 0 && opt->rigor == 0)
		return ; // ничего не печатаем
	if (num > 0 && opt->flag > 0)
	{
		if (opt->flag & FL_PLUS)
		{
			if (l < opt->rigor)
			{
				// нужно добавить знак +, нужно дополнить 0 до точности
			}
		}
	}
	else // если флаги равны 0 для любых чисел;
		ft_prn_str(s, opt);
	free(s);
	return ;

    // превращать в строку, считать длину цифр и добавлять при необходимости знак и доп до ширины
    //opt->len = opt->len + l;//печетать в зависимости от опций и записывать длину напечатанного.
// !!! после печати отчистить, то что вернул itoa
}

void           ft_prn_str(char *str, t_options *opt)
{
    int     l;
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

