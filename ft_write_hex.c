/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droslyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 19:16:16 by droslyn           #+#    #+#             */
/*   Updated: 2020/12/01 19:28:09 by droslyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

static void	ft_organized(unsigned int u_num, int l, t_options *opt)
{
	if (u_num == 0 && (opt->flag & FL_HESH))
		opt->flag = opt->flag - FL_HESH;
	if (opt->rigor != -1 && (opt->flag & FL_NULL))
		opt->flag = opt->flag - FL_NULL;
	if ((opt->flag & FL_NULL) && opt->rigor == -1 && opt->width > 0)
	{
		if (opt->flag & FL_HESH)
			opt->rigor = opt->width - 2;
		else
			opt->rigor = opt->width;
	}
	if ((opt->flag & FL_HESH) && opt->rigor + 2 > l)
		opt->rigor = opt->rigor + 2;
	else if (((l > opt->rigor) && (opt->rigor != 0)) || opt->rigor == -1)
		opt->rigor = l;
}

static void	ft_write_hex(unsigned int u_num, int l, char *s, t_options *opt)
{
	int		i;
	char	c0;

	i = 0;
	if (!(opt->flag & FL_MINUS))
	{
		if (opt->flag & FL_NULL)
			c0 = '0';
		else
			c0 = ' ';
		while ((opt->rigor + i++) < opt->width)
			opt->len = opt->len + write(1, &c0, 1);
	}
	if (opt->flag & FL_HESH && opt->rigor > 0 && u_num != 0)
		opt->len = opt->len + write(1, s, 2);
	while (opt->rigor != -1 && (l++ < opt->rigor))
		opt->len = opt->len + write(1, "0", 1);
	l--;
	if (opt->rigor == -1 ||
		((opt->rigor != 0 || u_num != 0) && !(opt->flag & FL_HESH)))
		opt->len = opt->len + write(1, s, ft_strlen(s));
	else if (opt->flag & FL_HESH && opt->rigor > 0)
		opt->len = opt->len + write(1, (s + 2), ft_strlen(s) - 2);
	while ((opt->flag & FL_MINUS) && (l++ < opt->width))
		opt->len = opt->len + write(1, " ", 1);
}

void		ft_prn_uxx(unsigned int u_num, t_options *opt)
{
	int		l;
	char	*s;

	if (opt->spcf == 'X')
		s = ft_itoa_hex(BASE_BIG, u_num, SIZE_BASE, opt);
	else if (opt->spcf == 'x')
		s = ft_itoa_hex(BASE_SMALL, u_num, SIZE_BASE, opt);
	else if (opt->spcf == 'u')
		return (ft_prn_un_int(u_num, opt));
	if ((opt->flag == 0 || opt->flag - FL_HESH == 0) && opt->rigor == -1)
	{
		ft_prn_str(s, opt);
		free(s);
		return ;
	}
	l = (int)ft_strlen(s);
	ft_organized(u_num, l, opt);
	if (opt->rigor == 0 && u_num == 0)
		ft_write_hex(u_num, 0, s, opt);
	else
		ft_write_hex(u_num, l, s, opt);
	free(s);
}

char		*ft_itoa_hex(char *base, unsigned int nbr, int len, t_options *opt)
{
	char	*str;
	int		i;

	if (!(str = malloc(11 * sizeof(char))))
		return (0);
	i = 0;
	ft_strlcpy(str, "0", 2);
	if (nbr == 0)
		return (str);
	while (nbr != 0)
	{
		str[i] = *(base + (nbr % len));
		nbr = nbr / len;
		i++;
	}
	if ((opt->flag & FL_HESH) && (ft_strchr("xX", opt->spcf)))
	{
		str[i++] = opt->spcf;
		str[i++] = '0';
	}
	str[i] = '\0';
	len = i;
	ft_str_reverse(str);
	return (str);
}
