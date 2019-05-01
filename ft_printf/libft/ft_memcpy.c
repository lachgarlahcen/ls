/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llachgar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 15:05:35 by llachgar          #+#    #+#             */
/*   Updated: 2018/10/09 21:14:48 by llachgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*str;
	char	*str1;
	size_t	i;

	if (n == 0 || dst == src)
		return (dst);
	str = (char *)dst;
	str1 = (char *)src;
	i = 0;
	while (n--)
	{
		str[i] = str1[i];
		i++;
	}
	return (dst);
}
