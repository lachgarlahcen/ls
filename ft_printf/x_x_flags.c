/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   X_x_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llachgar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 21:26:37 by llachgar          #+#    #+#             */
/*   Updated: 2019/01/31 21:55:05 by llachgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pre_x_x(t_flags *flags, char *str)
{
	int		i;
	char	*temp;

	if (!flags->p1)
		return (str);
	temp = ft_strdup(str);
	i = flags->pr - ft_strlen(str);
	while (i > 0)
	{
		str = ft_strjoin_f("0", str, 0, 1);
		i--;
	}
	if (flags->h && !is_zero(temp))
		str = ft_strjoin_f("0X", str, 0, 1);
	if (flags->pr == 0 && is_zero(temp))
		str = ft_strsub(str, 0, 0);
	free(temp);
	return (str);
}

char	*fd_x_x(t_flags *flags, char *str, int nbr)
{
	int		i;
	char	*temp;

	if (!flags->fd)
		return (str);
	i = flags->fd - ft_strlen(str);
	temp = ft_strdup(str);
	if (flags->h && flags->z && ft_strcmp(temp, "") && nbr != 0 && !flags->p1)
		i -= 2;
	while (i > 0)
	{
		if (flags->m)
			str = ft_strjoin_f(str, " ", 1, 0);
		else if (flags->z && nbr != 0 && !flags->p1)
			str = ft_strjoin_f("0", str, 0, 1);
		else
			str = ft_strjoin_f(" ", str, 0, 1);
		i--;
	}
	if (flags->h && flags->z && nbr != 0 && ft_strcmp(temp, "") && !flags->p1)
		str = ft_strjoin_f("0X", str, 0, 1);
	free(temp);
	return (str);
}

void	print_x_x(t_flags *flags, char *str, char c, int nbr)
{
	str = pre_x_x(flags, str);
	str = fd_x_x(flags, str, nbr);
	if (c == 'x')
		str = str_to_lower(str);
	ft_putstr(str);
	flags->nbr += ft_strlen(str);
	free(str);
}

void	x_x_flags(t_flags *flags, va_list va, char c)
{
	intmax_t	nbr;
	char		*str;

	nbr = parse_it(flags, va);
	if (nbr < 0)
		nbr = (unsigned)nbr;
	str = ft_itoa_base(nbr, 16);
	if (flags->h && !flags->p1 && !flags->z && !is_zero(str))
		str = ft_strjoin_f("0X", str, 0, 1);
	print_x_x(flags, str, c, nbr);
}
