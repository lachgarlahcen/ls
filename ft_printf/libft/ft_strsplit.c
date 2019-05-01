/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llachgar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 15:22:32 by llachgar          #+#    #+#             */
/*   Updated: 2018/10/19 20:51:31 by llachgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static int	word_len(const char *s, char c)
{
	int		len;

	len = 0;
	while (*s != c && *s++)
		len++;
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		tablen;
	int		i;

	if (!s || !c)
		return (NULL);
	tablen = ft_calcd(s, c) + 1;
	if (!(tab = (char **)malloc(sizeof(char*) * (tablen))))
		return (NULL);
	i = 0;
	while (tablen--)
	{
		while (*s == c && *s)
			s++;
		if (!*s)
			break ;
		tab[i] = ft_strsub(s, 0, word_len(s, c));
		while (*s != c && *s)
			s++;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
