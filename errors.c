/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llachgar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 21:14:42 by llachgar          #+#    #+#             */
/*   Updated: 2019/04/16 21:22:56 by llachgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			exists(char *filename, struct stat *buffer)
{
	int exist;

	exist = stat(filename, buffer);
	if (exist == 0)
		return (1);
	else
		return (0);
}

int			exist_err(char *file)
{
	struct stat buffer;

	if (exists(file, &buffer) == 0)
	{
		ft_printf("ft_ls: %s: %s\n", file, strerror(errno));
		return (0);
	}
	return (1);
}

void		show_files_errors(t_ls *ls)
{
	t_arg *tmp;

	if (!ls->f_r)
		return ;
	tmp = ls->f_r;
	while (tmp)
	{
		if (!exist_err(tmp->name))
			dell_node(&ls->f_r, tmp->name);
		tmp = tmp->next;
	}
	print_arg(ls);
	if (ls->arg != NULL)
		ft_printf("\n");
}

void		dell_node(t_arg **arg, char *key)
{
	t_arg *tmp;
	t_arg *prv;

	tmp = *arg;
	if (tmp != NULL && ft_strcmp(tmp->name, key) == 0)
	{
		*arg = tmp->next;
		free(tmp);
		return ;
	}
	while (tmp != NULL && ft_strcmp(tmp->name, key) != 0)
	{
		prv = tmp;
		tmp = tmp->next;
	}
	if (tmp == NULL)
		return ;
	prv->next = tmp->next;
	free(tmp);
}

float		opt(float max_l, t_ls *ls, int *cunt, t_free_tab **tabs)
{
	max_l = max_len(ls, cunt);
	max_l = next_8(max_l);
	ls->col_numb = ls->win_max.ws_col / max_l;
	if ((ls->tab = stock_directories(ls, *cunt, tabs)) == NULL)
	{
		ft_printf("ft_ls: %s: %s\n", ls->path, strerror(errno));
		return (-1);
	}
	if (ls->flags.t)
		ls_t(*ls, ls->tab, *cunt);
	else
		ls->tab = ascii_order(ls->tab, *cunt);
	if (ls->flags.r)
		ft_reverse(ls, *cunt);
	return (max_l);
}
