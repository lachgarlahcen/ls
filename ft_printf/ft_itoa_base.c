/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llachgar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 00:55:03 by llachgar          #+#    #+#             */
/*   Updated: 2019/01/31 22:41:17 by llachgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char	*ft_itoa_base(long int value, int base)
{
	int			i;
	char		*nbr;
	long int	tmp;

	i = 0;
	tmp = value;
	while (tmp > 0)
	{
		tmp = tmp / base;
		i++;
	}
	nbr = (char*)malloc(sizeof(nbr) * i);
	nbr[i] = '\0';
	if (value == 0)
	{
		free(nbr);
		nbr = ft_strdup("0");
	}
	while (value > 0)
	{
		i--;
		nbr[i] = (value % base) + (value % base > 9 ? 'A' - 10 : '0');
		value = value / base;
	}
	return (nbr);
}
