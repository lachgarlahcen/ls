/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llachgar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 22:13:03 by llachgar          #+#    #+#             */
/*   Updated: 2019/01/31 22:20:31 by llachgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*pre_s(t_flags *flags, char *str)
{
	if (flags->p1 && (flags->pr < (int)ft_strlen(str)))
		str = ft_strsub(str, 0, flags->pr);
	return (str);
}

char		*fd_s(t_flags *flags, char *str)
{
	int i;

	i = flags->fd - ft_strlen(str);
	while (i > 0)
	{
		if (flags->m)
			str = ft_strjoin_f(str, " ", 1, 0);
		else
			str = ft_strjoin_f(" ", str, 0, 1);
		i--;
	}
	return (str);
}

void		print_s(t_flags *flags, char *str)
{
	str = pre_s(flags, str);
	str = fd_s(flags, str);
	ft_putstr(str);
	flags->nbr += ft_strlen(str);
	free(str);
}

void		s_flag(t_flags *flags, va_list va)
{
	char	*str;

	str = va_arg(va, char *);
	if (str == NULL)
		str = ft_strdup("(null)");
	print_s(flags, ft_strdup(str));
}
