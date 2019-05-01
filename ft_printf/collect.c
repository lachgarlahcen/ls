/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llachgar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 15:10:38 by llachgar          #+#    #+#             */
/*   Updated: 2019/02/28 03:27:28 by llachgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_flags(t_flags *flags, int j)
{
	while (flags->str[j])
	{
		if (flags->str[j] == '-')
			flags->m = 1;
		else if (flags->str[j] == '+')
			flags->p = 1;
		else if (flags->str[j] == ' ')
			flags->s = 1;
		else if (flags->str[j] == '0')
			flags->z = 1;
		else if (flags->str[j] == '#')
			flags->h = 1;
		else
			return (j);
		j++;
	}
	return (j);
}

int		get_field_width(t_flags *flags, int i)
{
	int fd;

	fd = 0;
	while (flags->str[i] && flags->str[i] >= '0' && flags->str[i] <= '9')
	{
		fd = fd * 10 + flags->str[i] - '0';
		i++;
	}
	flags->fd = fd;
	return (i);
}

int		get_lenght_m(t_flags *flags, int i)
{
	while (flags->str[i])
	{
		if (flags->str[i] == 'l')
		{
			if (flags->str[i - 1] == 'l')
				flags->ll = 1;
			else
				flags->l = 1;
		}
		else if (flags->str[i] == 'h')
		{
			if (flags->str[i - 1] == 'h')
				flags->hh = 1;
			else
				flags->h1 = 1;
		}
		else
			return (i);
		i++;
	}
	return (i);
}

int		get_pr(t_flags *flags, int i)
{
	int pr;

	if (flags->str[i] == '.')
		i++;
	else
		return (i);
	pr = 0;
	while (flags->str[i] && flags->str[i] >= '0' && flags->str[i] <= '9')
	{
		pr = pr * 10 + flags->str[i] - '0';
		i++;
	}
	flags->pr = pr;
	flags->p1 = 1;
	return (i);
}
