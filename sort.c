/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llachgar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 02:07:31 by llachgar          #+#    #+#             */
/*   Updated: 2019/04/17 02:09:11 by llachgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_arg			*sort_arg_time(t_arg *arg)
{
	char			*temp;
	t_arg			*start;
	struct stat		f1;
	struct stat		f2;

	start = arg;
	while (arg && arg->next)
	{
		lstat(arg->name, &f1);
		lstat(arg->next->name, &f2);
		if (f1.st_mtime < f2.st_mtime)
		{
			temp = arg->next->name;
			arg->next->name = arg->name;
			arg->name = temp;
			arg = start;
			continue ;
		}
		arg = arg->next;
	}
	return (start);
}

t_arg			*reverse(t_arg *arg)
{
	t_arg *current;
	t_arg *prev;
	t_arg *next;

	current = arg;
	prev = NULL;
	next = NULL;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	return (prev);
}

t_max_ll		*get_max_arg(t_ls *ls)
{
	t_max_ll		*max;
	struct stat		st;
	t_arg			*tmp;

	max = (t_max_ll *)malloc(sizeof(t_max_ll));
	tmp = ls->f_r;
	max->lnk = 0;
	max->size = 0;
	max->usr = 0;
	max->grp = 0;
	max->minor = 0;
	max->major = 0;
	while (tmp)
	{
		if (lstat(tmp->name, &st) == 0)
		{
			max = comp_max(st, max);
		}
		tmp = tmp->next;
	}
	return (max);
}

void			ft_reverse(t_ls *ls, int cunt)
{
	int				i;
	struct dirent	sd;

	i = 0;
	cunt--;
	while (i < cunt / 2)
	{
		sd = ls->tab[i];
		ls->tab[i] = ls->tab[cunt - i];
		ls->tab[cunt - i] = sd;
		i++;
	}
}

t_arg			*sort_arg(t_arg *arg)
{
	char		*temp;
	t_arg		*start;

	start = arg;
	while (arg && arg->next)
	{
		if (ft_strcmp(arg->name, arg->next->name) > 0)
		{
			temp = arg->next->name;
			arg->next->name = arg->name;
			arg->name = temp;
			arg = start;
			continue ;
		}
		arg = arg->next;
	}
	return (start);
}
