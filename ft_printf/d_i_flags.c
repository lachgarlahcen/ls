/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_i_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llachgar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 14:28:20 by llachgar          #+#    #+#             */
/*   Updated: 2019/01/31 14:46:39 by llachgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*pre_d_i(t_flags *flags, char *str, int ng, int nbr)
{
	int i;

	if (!flags->p1)
		return (str);
	i = flags->pr - ft_strlen(str);
	while (i > 0)
	{
		str = ft_strjoin_f("0", str, 0, 1);
		i--;
	}
	if (nbr == 0 && flags->pr == 0)
		str = ft_strsub(str, 0, 0);
	if (ng)
		str = ft_strjoin_f("-", str, 0, 1);
	if (flags->p && !ng)
		str = ft_strjoin_f("+", str, 0, 1);
	if (!flags->p && flags->s && !ng)
		str = ft_strjoin_f(" ", str, 0, 1);
	return (str);
}

char		*fd_d_i(t_flags *flags, char *str, int ng)
{
	int i;

	if (!flags->fd)
		return (str);
	i = flags->fd - ft_strlen(str);
	if (flags->z && !flags->p1 && (flags->p || ng))
		i--;
	while (i > 0)
	{
		if (flags->m)
			str = ft_strjoin_f(str, " ", 1, 0);
		else if (flags->z && !flags->p1)
			str = ft_strjoin_f("0", str, 0, 1);
		else
			str = ft_strjoin_f(" ", str, 0, 1);
		i--;
	}
	if (flags->z && !flags->p1 && ng)
		str = ft_strjoin_f("-", str, 0, 1);
	if (flags->z && !flags->p1 && flags->p && !ng)
		str = ft_strjoin_f("+", str, 0, 1);
	return (str);
}

void		print_d_i(t_flags *flags, char *str, int ng, int nbr)
{
	if (!flags->p1 && (!flags->fd || (flags->fd && !flags->z)) && ng)
		str = ft_strjoin_f("-", str, 0, 1);
	if (!flags->p1 && (!flags->fd
				|| (flags->fd && !flags->z)) && flags->p && !ng)
		str = ft_strjoin_f("+", str, 0, 1);
	if (!flags->p && !ng && flags->s && ((!flags->p1 && !flags->fd)
				|| (!flags->p1 && flags->fd)))
		str = ft_strjoin_f(" ", str, 0, 1);
	str = pre_d_i(flags, str, ng, nbr);
	str = fd_d_i(flags, str, ng);
	ft_putstr(str);
	flags->nbr += ft_strlen(str);
	free(str);
}

void		d_i_flags(t_flags *flags, va_list va)
{
	unsigned long long	test;
	intmax_t			nbr;
	char				*str;
	int					ng;

	ng = 0;
	test = (unsigned long long)-9223372036854775808uLL;
	nbr = parse_it(flags, va);
	if ((unsigned long long)nbr != test)
		if (nbr < 0)
		{
			nbr *= -1;
			ng = 1;
		}
	str = ft_itoa_base(nbr, 10);
	if ((unsigned long long)nbr == test)
	{
		free(str);
		str = ft_strdup("9223372036854775808");
		ng = 1;
	}
	print_d_i(flags, str, ng, nbr);
}
