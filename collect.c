/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llachgar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 19:11:16 by llachgar          #+#    #+#             */
/*   Updated: 2019/04/16 21:14:06 by llachgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			collect_arg(t_ls *ls, char **argv, int i, int last_arg)
{
	struct stat	st;
	int			a;
	int			b;
	int			x;

	a = 0;
	b = 0;
	while (i > last_arg)
	{
		x = lstat(argv[i], &st);
		if (x == 0 && (file_type(st) == 'd' ||
					(file_type(st) == 'l' &&
					(argv[i][ft_strlen(argv[i]) - 1] != '/' && !ls->flags.l))))
			add_to_list(&a, &ls->arg, argv[i]);
		else
			add_to_list(&b, &ls->f_r, argv[i]);
		i--;
	}
	ls->arg = sort_arg(ls->arg);
	ls->f_r = sort_arg(ls->f_r);
}

void			set_flags(char **argv, t_ls *ls, int *k, int *l)
{
	int i;
	int j;

	i = *k;
	j = *l;
	while (argv[j][++i] != '\0')
		if (argv[j][i] == 'R')
			ls->flags.r1 = 1;
		else if (argv[j][i] == 'l')
			ls->flags.l = 1;
		else if (argv[j][i] == 'a')
			ls->flags.a = 1;
		else if (argv[j][i] == 'r')
			ls->flags.r = 1;
		else if (argv[j][i] == 't')
			ls->flags.t = 1;
		else
		{
			ft_printf("usage: ft_ls [-Raltr] [file ...]\n");
			exit(1);
		}
	*k = i;
	*l = j;
}

int				collect(int argc, char **argv, t_ls *ls)
{
	int		i;
	int		last_arg;
	int		j;
	int		k;

	last_arg = 0;
	j = 1;
	k = 0;
	while (j < argc)
	{
		if (argv[j][0] == '-')
		{
			ls->flags.flag_presence = 1;
			i = 0;
			if (!k)
				last_arg = j;
			set_flags(argv, ls, &i, &j);
		}
		else
			k = 1;
		j++;
	}
	return (last_arg);
}

struct dirent	*stock_directories(t_ls *ls, int dir_nums, t_free_tab **tabs)
{
	DIR				*d;
	struct dirent	*tab;
	int				index;

	tab = (struct dirent *)malloc(sizeof(struct dirent) * dir_nums);
	*tabs = add_to_tabs(tabs, tab);
	if (!(d = opendir(ls->path)))
		return (NULL);
	index = 0;
	while (dir_nums)
	{
		tab[index] = *readdir(d);
		if (tab[index].d_name[0] != '.' || (tab[index].d_name[0] == '.' &&
					ls->flags.a))
		{
			index++;
			dir_nums--;
		}
	}
	closedir(d);
	return (tab);
}

void			add_to_list(int *a, t_arg **arg, char *str)
{
	t_arg *tmp;

	tmp = *arg;
	if (!*a)
	{
		*arg = create_arg(str);
		*a = 1;
	}
	else
	{
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = create_arg(str);
	}
}
