/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droslyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 20:45:09 by droslyn           #+#    #+#             */
/*   Updated: 2020/11/16 20:50:13 by droslyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPRINTF_H
# define LIBPRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
#include <string.h>
# include "libft.h"

#define FL_NON      0b00000000
#define FL_MINUS    0b00000001
#define FL_PLUS     0b00000010
#define FL_SPACE    0b00000100
#define FL_HESH     0b00001000
#define FL_NULL     0b00010000
#define BASE_BIG	"0123456789ABCDEF"
#define BASE_SMALL	"0123456789abcdef"
#define SIZE_BASE	16
#define NULL_STR	"(null)"

typedef struct		s_options
{
    unsigned char   flag;
    int             width;
    int             rigor;
    char 			spcf;
    size_t          len;
    va_list	    	ap;
}					t_options;


int		            ft_printf(const char *format_str, ...);
int                 ft_checkopt(char *str, t_options *opt);
void 		        ft_checkflag(char c, t_options *opt);
int                 ft_checkwdt(char *str, t_options *opt);
int                 ft_checkrigor(char *str, t_options *opt);
void                ft_checktype(t_options *opt);
void                ft_prn_uxx(unsigned int u_num, t_options *opt);
void                ft_prn_di(int num, t_options *opt);
void                ft_prn_str(char *str, t_options *opt);
void                ft_prn_char(unsigned char c, t_options *opt);

void 		ft_add_rigor_posit(char c, size_t l, char *s, t_options *opt);
int			ft_abs(int n);

char				*ft_itoa_hex(char *base, unsigned int nbr, size_t len, t_options *opt);
void 				ft_add_rigor_hex(size_t l, char *s, t_options *opt);

#endif
