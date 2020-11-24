/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droslyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 20:06:41 by droslyn           #+#    #+#             */
/*   Updated: 2020/11/25 00:55:41 by droslyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"


char 	*ft_change_base(char *base, unsigned int nbr, size_t len)
{
	char			*str;
	char 			tmp;
	int				i;

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

int	 main()
{
	char *str;

	str = ft_change_base("0123456789abcdef", 123456, 16);
	return 0;
}
