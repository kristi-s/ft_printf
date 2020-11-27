#include "libprintf.h"

void 		ft_add_rigor_hex(size_t l, char *s, t_options *opt)
{
	int 	i;
	char	c0;

	i = 0;
	if (!(opt->flag & FL_MINUS))
	{
		if ((opt->flag & FL_NULL) && ft_strncmp(s, "0", 2))
			c0 = '0';
		else
			c0 = ' ';
		while ((opt->rigor + i++) < opt->width)
			opt->len = opt->len + write(1, &c0, 1);
	}
	while (l++ < opt->rigor)	//наращивается l на 1 в любом случае
		opt->len = opt->len + write(1, "0", 1);
	l--;
	if (ft_strncmp(s, "0", 2) || opt->rigor != 0)
		opt->len = opt->len + write(1, s, ft_strlen(s));
	while ((opt->flag & FL_MINUS) && (l++ < opt->width))
		opt->len = opt->len + write(1, " ", 1);
	return ;
}

char 	*ft_itoa_hex(char *base, unsigned int nbr, size_t len, t_options *opt)
{
	char			*str;
	char 			tmp;
	int				i;

	if (!(str = malloc(11 * sizeof(char))))
		return (0);
	i = 0;
	str[0] = '0';
	str[1] = '\0';
	if ((opt->flag & FL_HESH) && (ft_strchr("xX", opt->spcf)))
	{
		str[1] = opt->spcf;
		str[2] = '0';
		str[3] = '\0';
		i = 2;
	}
	if (nbr == 0)
		return (str);
	while (nbr != 0)
	{
		str[i] = *(base + (nbr % len));
		nbr = nbr / len;
		i++;
	}
	str[i] = '\0';
	len = i;
	while (i > len / 2)
	{
		tmp = str [i - 1];
		str[i - 1] = str[len - i];
		str[len - i] = tmp;
		i--;
	}
//	write(1, str, len);
	return (str);

}
/*
int	 main()
{
	char *str;

	str = ft_change_base("0123456789abcdef", 123456, 16);
	return 0;
}
*/