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
    l = 0;
    // превращать в строку, считать длину цифр и добавлять при необходимости знак и доп до ширины
    //opt->len = opt->len + l;//печетать в зависимости от опций и записывать длину напечатанного.

}

void           ft_prn_str(char *str, t_options *opt)
{
    int     l;

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
                opt->len = opt->len + write(1, "", 1); // на каждой итерации печатаем space
        }
    }
    // еще раз прочитать в каком случае учитывать (печатать последний символ), если длина короче?
    // считать длину, при необходимости обрезать, увеличивать ширину
    //opt->len = opt->len + l;//печетать в зависимости от опций и записывать длину напечатанного.

}

void            ft_prn_char(char c, t_options *opt)
{
    int     l;
    l = 0;
    // считать длину прочитанного с учетом ширины, учитыть флаги '-' или '0'
    //opt->len = opt->len + l;
}

