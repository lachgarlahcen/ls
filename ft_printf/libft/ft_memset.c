/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llachgar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 14:07:08 by llachgar          #+#    #+#             */
/*   Updated: 2018/10/05 18:00:29 by llachgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char *str;

	str = s;
	while (len > 0)
	{
		*str = (unsigned char)c;
		str++;
		len--;
	}
	return (s);
}
