/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llachgar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 22:20:48 by llachgar          #+#    #+#             */
/*   Updated: 2019/01/31 22:26:30 by llachgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*pre_p(t_flags *flags, char *str)
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
	str = ft_strjoin_f("0x", str, 0, 1);
	return (str);
}

char		*fd_p(t_flags *flags, char *str)
{
	int i;

	if (!flags->fd)
		return (str);
	i = flags->fd - ft_strlen(str);
	if (flags->z && !flags->p1)
		i -= 2;
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
	if (flags->z && !flags->p1)
		str = ft_strjoin_f("0x", str, 0, 1);
	return (str);
}

void		print_p(t_flags *flags, char *str)
{
	str = pre_p(flags, str);
	str = fd_p(flags, str);
	flags->nbr += ft_strlen(str);
	ft_putstr(str);
	free(str);
}

void		p_flag(t_flags *flags, va_list va)
{
	char		*str;
	intmax_t	nbr;

	nbr = va_arg(va, intmax_t);
	str = ft_itoa_base(nbr, 16);
	str = str_to_lower(str);
	if (!flags->z && !flags->p1)
		str = ft_strjoin_f("0x", str, 0, 1);
	print_p(flags, str);
}
