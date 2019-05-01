/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llachgar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 22:28:32 by llachgar          #+#    #+#             */
/*   Updated: 2019/01/31 22:33:36 by llachgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t		parse_it_u(t_flags *flags, va_list va)
{
	intmax_t nbr;

	nbr = va_arg(va, intmax_t);
	if (flags->hh)
		nbr = (unsigned char)nbr;
	else if (flags->h1)
		nbr = (unsigned short)nbr;
	else if (flags->l && !flags->ll)
		nbr = (unsigned long)nbr;
	else if (flags->ll)
		nbr = (unsigned long long)nbr;
	else
		nbr = (unsigned int)nbr;
	return (nbr);
}

char			*pre_u(t_flags *flags, char *str, int nbr)
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
	if (nbr == 0 && !flags->pr)
		str = ft_strsub(str, 0, 0);
	return (str);
}

char			*fd_u(t_flags *flags, char *str)
{
	int i;

	if (!flags->fd)
		return (str);
	i = flags->fd - ft_strlen(str);
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
	return (str);
}

void			print_u(t_flags *flags, char *str, int nbr)
{
	str = pre_u(flags, str, nbr);
	str = fd_u(flags, str);
	flags->nbr += ft_strlen(str);
	ft_putstr(str);
	free(str);
}

void			u_flag(t_flags *flags, va_list va)
{
	char		*str;
	intmax_t	nbr;

	nbr = parse_it_u(flags, va);
	str = ft_itoa_base(nbr, 10);
	print_u(flags, str, nbr);
}
