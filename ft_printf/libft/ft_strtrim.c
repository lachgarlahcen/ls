/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llachgar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 20:51:34 by llachgar          #+#    #+#             */
/*   Updated: 2018/10/09 22:23:09 by llachgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*s1;
	int		len;

	if (!s)
		return (NULL);
	s1 = (char *)s;
	while ((*s1 == '\n') || (*s1 == '\t') || (*s1 == ' '))
		s1++;
	if (*s1 == '\0')
		return (ft_strnew(0));
	len = ft_strlen(s1) - 1;
	while ((s1[len] == '\n') || (s1[len] == '\t') || (s1[len] == ' '))
		len--;
	return (ft_strsub(s1, 0, len + 1));
}
