/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llachgar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 19:30:00 by llachgar          #+#    #+#             */
/*   Updated: 2018/10/05 19:52:18 by llachgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int					res;
	int					i;
	const unsigned char	*s3;
	const unsigned char	*s4;

	i = 0;
	res = 0;
	s3 = s1;
	s4 = s2;
	while (res == 0 && n > 0)
	{
		res = s3[i] - s4[i];
		i++;
		n--;
	}
	return (res);
}
