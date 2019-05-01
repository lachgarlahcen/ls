/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llachgar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 01:03:41 by llachgar          #+#    #+#             */
/*   Updated: 2019/01/31 22:11:34 by llachgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t		parse_it(t_flags *flags, va_list va)
{
	intmax_t nbr;

	nbr = va_arg(va, intmax_t);
	if (flags->hh)
		nbr = (char)nbr;
	else if (flags->h1)
		nbr = (short)nbr;
	else if (flags->l && !flags->ll)
		nbr = (long)nbr;
	else if (flags->ll)
		nbr = (long long)nbr;
	else
		nbr = (int)nbr;
	return (nbr);
}

char			*str_to_lower(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
	return (str);
}

int				is_zero(char *str)
{
	if (!ft_strcmp("0", str))
		return (1);
	return (0);
}

char			*pre(t_flags *flags, char *str, int s)
{
	int i;
	int prt;
	int nbr;
	int ng;

	ng = 0;
	prt = flags->pr;
	nbr = ft_atoi(str);
	if (nbr < 0)
	{
		nbr *= -1;
		str = ft_itoa(nbr);
		ng = 1;
	}
	i = prt - ft_strlen(str);
	while (i > 0 && !s)
		(str = ft_strjoin_f("0", str, 0, 1)) ? i-- : 1 == 1;
	if (s || (!s && !ft_strcmp(str, "0")))
		str = ft_strsub(str, 0, prt);
	if (ng)
		str = ft_strjoin_f("-", str, 0, 1);
	else if (flags->p)
		str = ft_strjoin_f("+", str, 0, 1);
	return (str);
}
