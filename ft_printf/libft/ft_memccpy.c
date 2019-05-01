/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llachgar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 16:55:27 by llachgar          #+#    #+#             */
/*   Updated: 2018/10/09 21:15:14 by llachgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	int		i;
	char	*str;
	char	*str1;

	str = (char *)dst;
	str1 = (char *)src;
	i = 0;
	while (n > 0)
	{
		str[i] = str1[i];
		if ((unsigned char)str1[i] == (unsigned char)c)
		{
			return (dst + i + 1);
		}
		i++;
		n--;
	}
	return (NULL);
}
