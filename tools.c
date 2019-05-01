/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 16:52:10 by rel-hada          #+#    #+#             */
/*   Updated: 2019/04/17 02:11:35 by llachgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

float			next_8(float max)
{
	float i;

	i = 8;
	while (max >= i)
	{
		i += 8;
	}
	return (i);
}

struct dirent	*ascii_order(struct dirent *tab, int len)
{
	int				i;
	int				j;
	struct dirent	temp;

	i = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if (ft_strcmp(tab[j].d_name, tab[j + 1].d_name) > 0)
			{
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	return (tab);
}

int				max_len(t_ls *ls, int *cunt)
{
	int max_len;
	int len;

	max_len = 0;
	if (!(ls->r1 = opendir(ls->path)))
		return (0);
	while ((ls->sd = readdir(ls->r1)) != NULL)
	{
		if (ls->sd->d_name[0] == '.' && !ls->flags.a)
			continue ;
		(*cunt)++;
		len = ft_strlen(ls->sd->d_name);
		if (len > max_len)
			max_len = len;
	}
	closedir(ls->r1);
	return (max_len);
}

int				rnd(int a, int c)
{
	int b;

	if (c == 0)
		c = 1;
	b = a / c;
	if ((a % c) != 0)
		b++;
	if (b == 0)
		b++;
	return (b);
}
