/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llachgar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 13:13:01 by llachgar          #+#    #+#             */
/*   Updated: 2018/10/07 16:16:41 by llachgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char *str1;

	str1 = (unsigned char *)str;
	while (n > 0)
	{
		if (*str1 == (unsigned char)c)
			return (str1);
		str1++;
		n--;
	}
	return (NULL);
}
