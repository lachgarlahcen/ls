/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llachgar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 21:05:52 by llachgar          #+#    #+#             */
/*   Updated: 2019/01/31 21:08:22 by llachgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_c(char c, t_flags *flags)
{
	if (flags->m)
		write(1, &c, 1);
	while ((flags->fd - 1) > 0)
	{
		write(1, " ", 1);
		flags->nbr++;
		flags->fd--;
	}
	flags->nbr++;
	if (!flags->m)
		write(1, &c, 1);
}

void	c_flag(t_flags *flags, va_list va)
{
	char c;

	c = (unsigned char)va_arg(va, int);
	print_c(c, flags);
}
