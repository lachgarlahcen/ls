/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llachgar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 21:10:08 by llachgar          #+#    #+#             */
/*   Updated: 2019/01/31 21:20:50 by llachgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef	struct	s_flags
{

	int			is;
	int			m;
	int			p;
	int			s;
	int			z;
	int			h;
	int			fd;
	int			l;
	int			ll;
	int			h1;
	int			hh;
	int			pr;
	int			p1;
	char		*str;
	int			nbr;
}				t_flags;

char			*ft_itoa_base(long int value, int base);
char			*str_to_lower(char *str);
void			to_hexa(long int n, t_flags *flags, int i);
char			*pre(t_flags *flags, char *str, int s);
int				get_flags(t_flags *flags, int j);
int				get_field_width(t_flags *flags, int i);
int				get_lenght_m(t_flags *flags, int i);
int				get_pr(t_flags *flags, int i);
void			o_flag(t_flags *flags, va_list va);
void			u_flag(t_flags *flags, va_list va);
void			p_flag(t_flags *flags, va_list va);
void			c_flag(t_flags *flags, va_list va);
void			s_flag(t_flags *flags, va_list va);
void			x_x_flags(t_flags *flags, va_list va, char c);
intmax_t		parse_it(t_flags *flags, va_list va);
int				is_zero(char *str);
void			d_i_flags(t_flags *flags, va_list va);
int				ft_printf(const char *str, ...);
void			print_c(char c, t_flags *flags);
#endif
