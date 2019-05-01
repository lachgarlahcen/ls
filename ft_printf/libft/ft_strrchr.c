/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llachgar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 18:50:59 by llachgar          #+#    #+#             */
/*   Updated: 2018/10/19 21:00:42 by llachgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

static int	ft_find(char *str, int c)
{
	int len;

	len = ft_strlen(str);
	while (len >= 0)
	{
		if (str[len] == c)
		{
			return (len);
		}
		len--;
	}
	return (-1);
}

char		*ft_strrchr(const char *str, int c)
{
	int		pos;
	char	*str1;

	str1 = (char *)str;
	pos = ft_find(str1, c);
	if (pos >= 0)
		return (str1 + pos);
	return ((char *)NULL);
}
