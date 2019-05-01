/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llachgar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 19:11:52 by llachgar          #+#    #+#             */
/*   Updated: 2018/10/09 22:21:26 by llachgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s1;
	int		i;

	if (!(s1 = ft_strnew(len)) || !s)
		return (NULL);
	i = -1;
	while (++i < (int)len && (char)s[start])
		s1[i] = (char)s[start++];
	s1[i] = '\0';
	return (s1);
}
