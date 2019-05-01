/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_files.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llachgar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 20:46:44 by llachgar          #+#    #+#             */
/*   Updated: 2019/04/16 14:54:52 by llachgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			get_info_arg(char *file, t_max_ll *max)
{
	struct stat		st;
	struct group	*gr;
	struct passwd	*pw;

	if (lstat(file, &st) == 0)
	{
		gr = getgrgid(st.st_gid);
		pw = getpwuid(st.st_uid);
		put_mode(st, file);
		put_space(max->lnk, ft_itoa_base(st.st_nlink, 10), 0);
		put_space(max->usr, pw->pw_name, 1);
		put_space(max->grp, gr->gr_name, 1);
		get_size(st, max->size, max->major);
		get_time(st.st_mtime);
		ft_printf("%s", file);
		if (file_type(st) == 'l')
			get_link_path(file);
		ft_putchar('\n');
	}
}

void			print_arg_l(t_ls *ls)
{
	t_max_ll	*max;
	t_arg		*tmp;

	max = get_max_arg(ls);
	tmp = ls->f_r;
	while (tmp)
	{
		get_info_arg(tmp->name, max);
		tmp = tmp->next;
	}
}

char			**max_len_arg(t_ls *ls, int *i, int *max)
{
	t_arg	*tmp;
	int		len;
	char	**tab;

	*i = 0;
	*max = 0;
	tmp = ls->f_r;
	while (tmp)
	{
		if ((int)ft_strlen(tmp->name) > *max)
			*max = ft_strlen(tmp->name);
		*i += 1;
		tmp = tmp->next;
	}
	*max = (int)next_8((float)*max);
	tab = (char **)malloc(sizeof(char *) * *i);
	tmp = ls->f_r;
	len = 0;
	while (tmp)
	{
		tab[len++] = tmp->name;
		tmp = tmp->next;
	}
	free(ls->f_r);
	return (tab);
}

void			print_arg_normal(t_ls *ls, char **tab)
{
	int		max;
	int		cunt;
	int		j;
	int		i;
	int		k;

	tab = max_len_arg(ls, &cunt, &max);
	ls->col_numb = ls->win_max.ws_col / max;
	j = rnd(cunt, ls->col_numb);
	i = 0;
	while (i < j)
	{
		k = 0;
		while ((k * j + i) < cunt)
		{
			print_with_space(tab[(k * j + i)], max, ((k + 1) * j + i) < cunt);
			k++;
		}
		ft_printf("\n");
		i++;
	}
}

void			print_arg(t_ls *ls)
{
	char	**tab;

	tab = NULL;
	if (!ls->f_r)
		return ;
	if (ls->flags.t)
		ls->f_r = sort_arg_time(ls->f_r);
	if (ls->flags.r)
		ls->f_r = reverse(ls->f_r);
	if (ls->flags.l)
		print_arg_l(ls);
	else
		print_arg_normal(ls, tab);
}
