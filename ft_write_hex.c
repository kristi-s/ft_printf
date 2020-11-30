/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droslyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 19:16:16 by droslyn           #+#    #+#             */
/*   Updated: 2020/11/30 19:24:57 by droslyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

void 		ft_add_rigor_hex(unsigned int u_num, size_t l, char *s, t_options *opt)
{
	int 	i;
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
/////////

	if (opt->flag & FL_HESH && opt->rigor > 0 && u_num != 0)
		opt->len = opt->len + write(1, s, 2);

/////////
	while (opt->rigor != -1 && ((int)l++ < opt->rigor))
		opt->len = opt->len + write(1, "0", 1);
	l--;
	if (opt->rigor == -1 || ((opt->rigor != 0 || u_num != 0) && !(opt->flag & FL_HESH)))
		opt->len = opt->len + write(1, s, ft_strlen(s));
	else if (opt->flag & FL_HESH && opt->rigor > 0)
		opt->len = opt->len + write(1, (s + 2), ft_strlen(s) - 2);
	while ((opt->flag & FL_MINUS) && ((int)l++ < opt->width))
		opt->len = opt->len + write(1, " ", 1);
	return ;
}

char 		*ft_itoa_hex(char *base, unsigned int nbr, size_t len, t_options *opt)
{
	char	*str;
	char 	tmp;
	int		i;

	if (!(str = malloc(11 * sizeof(char))))
		return (0);
	i = 0;
	str[0] = '0';
	str[1] = '\0';
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
	while (i > (int)len / 2)
	{
		tmp = str [i - 1];
		str[i - 1] = str[len - i];
		str[len - i] = tmp;
		i--;
	}
	return (str);
}


