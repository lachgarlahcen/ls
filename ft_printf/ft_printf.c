/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llachgar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 17:56:38 by llachgar          #+#    #+#             */
/*   Updated: 2019/01/31 21:42:15 by llachgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags		*init(t_flags *flags)
{
	flags->m = 0;
	flags->p = 0;
	flags->s = 0;
	flags->z = 0;
	flags->h = 0;
	flags->fd = 0;
	flags->ll = 0;
	flags->l = 0;
	flags->h1 = 0;
	flags->hh = 0;
	flags->pr = 0;
	flags->p1 = 0;
	flags->is = 0;
	return (flags);
}

void		print_the_conv(va_list va, t_flags *flags, int i)
{
	if (flags->str[i] == 'd' || flags->str[i] == 'i')
		d_i_flags(flags, va);
	else if (flags->str[i] == 's')
		s_flag(flags, va);
	else if (flags->str[i] == 'p')
		p_flag(flags, va);
	else if ((flags->str[i] == 'x' || flags->str[i] == 'X'))
		x_x_flags(flags, va, flags->str[i]);
	else if (flags->str[i] == 'u')
		u_flag(flags, va);
	else if (flags->str[i] == 'c')
		c_flag(flags, va);
	else if (flags->str[i] == 'o')
		o_flag(flags, va);
	else
		print_c(flags->str[i], flags);
}

int			by_type(va_list va, t_flags *flags, int i)
{
	i = get_flags(flags, i);
	i = get_field_width(flags, i);
	i = get_pr(flags, i);
	i = get_lenght_m(flags, i);
	print_the_conv(va, flags, i);
	flags = init(flags);
	return (i);
}

int			ft_printf(const char *str, ...)
{
	va_list		va;
	int			i;
	t_flags		*flags;
	int			nbr;

	flags = (t_flags *)malloc(sizeof(t_flags));
	flags->str = ft_strdup(str);
	flags->nbr = 0;
	flags = init(flags);
	va_start(va, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			i = by_type(va, flags, ++i);
		else
			(write(1, &str[i], 1)) ? flags->nbr++ : 1 == 1;
		i++;
	}
	va_end(va);
	nbr = flags->nbr;
	free(flags->str);
	free(flags);
	return (flags->nbr);
}
