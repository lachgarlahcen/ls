/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 16:30:09 by rel-hada          #+#    #+#             */
/*   Updated: 2019/04/16 16:42:52 by llachgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ls_normal(t_ls *ls, t_free_tab **tabs)
{
	float		max_l;
	int			cunt;
	int			i;
	int			j;
	int			k;

	cunt = 0;
	i = 0;
	max_l = 0.0;
	max_l = opt(max_l, ls, &cunt, tabs);
	j = rnd(cunt, ls->col_numb);
	while (i < j)
	{
		k = 0;
		while ((k * j + i) < cunt)
		{
			print_with_space(ls->tab[(k * j + i)].d_name, max_l,
					((k + 1) * j + i) < cunt);
			k++;
		}
		ft_printf("\n");
		i++;
	}
	return (cunt);
}

t_ls		*init_ls(void)
{
	t_ls	*ls;

	ls = (t_ls *)malloc(sizeof(t_ls));
	ls->tabs = NULL;
	ls->chars = NULL;
	ls->flags.r1 = 0;
	ls->flags.l = 0;
	ls->flags.a = 0;
	ls->flags.r = 0;
	ls->flags.t = 0;
	ls->arg = NULL;
	ls->f_r = NULL;
	ls->flags.flag_presence = 0;
	ioctl(0, TIOCGWINSZ, &ls->win_max);
	return (ls);
}

t_arg		*create_arg(char *str)
{
	t_arg *arg;

	if (!(arg = (t_arg *)malloc(sizeof(t_arg))))
		return (NULL);
	arg->name = str;
	arg->next = NULL;
	return (arg);
}

void		path_exist(t_ls *ls, t_arg *tmp, int path_num)
{
	int i;

	i = 0;
	while (tmp != NULL)
	{
		if (path_num != 1)
			ft_printf("%s:\n", tmp->name);
		ls->path = ft_strdup(tmp->name);
		if (ls->flags.flag_presence == 0)
			ls_normal(ls, &ls->tabs);
		else
		{
			if (ls->flags.r1 == 1)
				ls_r(*ls, &ls->tabs, &ls->chars);
			else if (ls->flags.l == 1)
				ls_l(ls, &ls->tabs);
			else
				ls_normal(ls, &ls->tabs);
		}
		tmp = tmp->next;
		if (tmp != NULL)
			ft_printf("\n");
		i++;
	}
}

int			main(int argc, char **argv)
{
	t_ls	*ls;
	int		last_arg;

	ls = init_ls();
	last_arg = collect(argc, argv, ls);
	collect_arg(ls, argv, argc - 1, last_arg);
	show_files_errors(ls);
	if ((argc - last_arg + 1) && ls->arg != NULL)
		path_exist(ls, ls->arg, (argc - (last_arg + 1)));
	else if (!(argc - (last_arg + 1)))
	{
		ls->path = ft_strdup(".");
		ls->chars = add_to_chars(&ls->chars, ls->path);
		if (ls->flags.r1 == 1)
			ls_r(*ls, &ls->tabs, &ls->chars);
		else if (ls->flags.l == 1)
			ls_l(ls, &ls->tabs);
		else
			ls_normal(ls, &ls->tabs);
	}
	free_aloc_tabs(ls);
	free_aloc_chars(ls);
	free(ls);
	return (0);
}
