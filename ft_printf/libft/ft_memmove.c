/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llachgar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 17:51:04 by llachgar          #+#    #+#             */
/*   Updated: 2018/10/07 14:37:46 by llachgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*str;
	char	*str1;
	size_t	i;

	i = -1;
	str = (char *)src;
	str1 = (char *)dst;
	if (str < str1)
		while ((int)(--len) >= 0)
			*(str1 + len) = *(str + len);
	else
		while (++i < len)
			*(str1 + i) = *(str + i);
	return (dst);
}
