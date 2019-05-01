/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llachgar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 21:43:45 by llachgar          #+#    #+#             */
/*   Updated: 2018/10/11 14:14:22 by llachgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char a;
	long n1;

	n1 = n;
	if (n1 == 0)
		ft_putchar_fd('0', fd);
	if (n1 < 0)
	{
		ft_putchar_fd('-', fd);
		n1 *= -1;
	}
	if (n1 != 0)
	{
		if ((n1 / 10))
			ft_putnbr_fd(n1 / 10, fd);
		a = (n1 % 10) + '0';
		ft_putchar_fd(a, fd);
	}
}
