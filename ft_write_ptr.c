/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droslyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 00:58:50 by droslyn           #+#    #+#             */
/*   Updated: 2020/12/01 00:59:20 by droslyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

char			*ft_str_reverse(char *str)
{
	size_t		i;
	size_t		len;
	char		tmp;

	len = ft_strlen(str);
	i = len;
	while (i > len / 2)
	{
		tmp = str[i - 1];
		str[i - 1] = str[len - i];
		str[len - i] = tmp;
		i--;
	}
	return (str);
}

static char		*ft_itoa_ptr(char *base, unsigned long long nbr, int len)
{
	char		*str;
	int			i;

	if (nbr == 0)
	{
		if (!(str = ft_strdup(NULL_PTR)))
			return (0);
		return (str);
	}
	if (!(str = malloc(18 * sizeof(char))))
		return (0);
	i = 0;
	while (nbr != 0)
	{
		str[i] = *(base + (nbr % len));
		nbr = nbr / len;
		i++;
	}
	str[i++] = 'x';
	str[i++] = '0';
	str[i] = '\0';
	ft_str_reverse(str);
	return (str);
}

void			ft_prn_ptr(unsigned long long l_num, t_options *opt)
{
	char		*s;

	if (!(s = ft_itoa_ptr(BASE_SMALL, l_num, SIZE_BASE)))
		return ;
	if (l_num == 0 && opt->rigor == 0)
		opt->rigor = 2;
	else if (opt->rigor == 0)
		opt->rigor = -1;
	ft_prn_str(s, opt);
	free(s);
	return ;
}
