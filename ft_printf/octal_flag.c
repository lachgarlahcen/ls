/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llachgar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 21:43:44 by llachgar          #+#    #+#             */
/*   Updated: 2019/01/31 21:47:21 by llachgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*fd_o(t_flags *flags, char *str)
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

char	*pre_o(t_flags *flags, char *str, int nbr)
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
	if (nbr == 0 && !flags->h && !flags->pr)
		str = ft_strsub(str, 0, 0);
	return (str);
}

void	print_o(t_flags *flags, char *str, int nbr)
{
	str = pre_o(flags, str, nbr);
	str = fd_o(flags, str);
	flags->nbr += ft_strlen(str);
	ft_putstr(str);
	free(str);
}

void	o_flag(t_flags *flags, va_list va)
{
	char		*str;
	intmax_t	nbr;

	nbr = parse_it(flags, va);
	if (nbr < 0)
		nbr = (unsigned)nbr;
	str = ft_itoa_base(nbr, 8);
	if (flags->h && ft_strcmp("0", str))
		str = ft_strjoin_f("0", str, 0, 1);
	print_o(flags, str, nbr);
}
