/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llachgar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 11:31:10 by llachgar          #+#    #+#             */
/*   Updated: 2018/10/09 22:17:18 by llachgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	char		*str1;
	char		*str2;
	int			len;

	if (*s2 == '\0')
		return ((char *)s1);
	str1 = (char *)s1;
	str2 = (char *)s2;
	len = ft_strlen(str2);
	i = 0;
	while (str1[i] != '\0' && (i + len) <= n)
	{
		if (ft_strncmp(s1 + i, s2, len) == 0)
		{
			return (str1 + i);
		}
		i++;
	}
	return (NULL);
}
