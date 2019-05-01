/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 16:50:06 by rel-hada          #+#    #+#             */
/*   Updated: 2019/04/19 21:15:39 by llachgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		repeat_r(t_ls *ls, int j, t_free_tab **tabs, t_free_char **chars)
{
	if (ls->tab[j].d_type == DT_DIR)
	{
		if (ft_strcmp(ls->path, "/") == 0)
			ls->path = ft_strjoin("/", ls->tab[j].d_name);
		else
			ls->path = ft_strjoin_f(ls->path,
					ft_strjoin("/", ls->tab[j].d_name), 0, 1);
		*chars = add_to_chars(chars, ls->path);
		ft_printf("\n%s:\n", ls->path);
		ls->dir = opendir(ls->path);
		ls_r(*ls, tabs, chars);
		if (ls->dir != NULL)
			closedir(ls->dir);
	}
}

void		ls_r(t_ls ls, t_free_tab **tabs, t_free_char **chars)
{
	int				i;
	int				j;
	char			*str;

	if (ls.flags.l)
		i = ls_l(&ls, tabs);
	else
		i = ls_normal(&ls, tabs);
	if (i < 0)
		return ;
	j = 0;
	while (j < i)
	{
		if (ft_strcmp(ls.tab[j].d_name, ".") == 0 ||
				ft_strcmp(ls.tab[j].d_name, "..") == 0)
		{
			j++;
			continue ;
		}
		str = ft_strdup(ls.path);
		*chars = add_to_chars(chars, str);
		repeat_r(&ls, j, tabs, chars);
		ls.path = str;
		j++;
	}
}
