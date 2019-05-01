/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llachgar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 17:39:29 by llachgar          #+#    #+#             */
/*   Updated: 2018/10/19 21:05:27 by llachgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_calclen(long n)
{
	int		i;

	i = 0;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	if (!n)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int		ft_calcd(char const *str, char c)
{
	int i;
	int j;

	i = -1;
	j = 0;
	while (str[++i])
		if (str[i] != c && str[i - 1] == c)
			j++;
	return (j);
}

int		ft_is_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int		ft_is_upper(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

t_list	*find_elem(t_list *list, void *content)
{
	if (!content)
		return (NULL);
	while (list)
	{
		if (ft_memcmp(list->content, content, list->content_size))
			return (list);
		list = list->next;
	}
	return (NULL);
}
