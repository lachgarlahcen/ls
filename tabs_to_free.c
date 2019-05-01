/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabs_to_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llachgar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 21:09:54 by llachgar          #+#    #+#             */
/*   Updated: 2019/04/19 21:12:28 by llachgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_free_tab		*add_to_tabs(t_free_tab **tabs, struct dirent *tab)
{
	t_free_tab *tmp;

	tmp = (t_free_tab *)malloc(sizeof(t_free_tab));
	tmp->tab = tab;
	tmp->n = *tabs;
	return (tmp);
}

void			free_aloc_tabs(t_ls *ls)
{
	t_free_tab *tmp;

	while (ls->tabs != NULL)
	{
		tmp = ls->tabs;
		ls->tabs = ls->tabs->n;
		free(tmp->tab);
		free(tmp);
	}
}

t_free_char		*add_to_chars(t_free_char **chars, char *str)
{
	t_free_char *tmp;

	tmp = (t_free_char *)malloc(sizeof(t_free_char));
	tmp->str = str;
	tmp->n = *chars;
	return (tmp);
}

void			free_aloc_chars(t_ls *ls)
{
	t_free_char *tmp;

	while (ls->chars != NULL)
	{
		tmp = ls->chars;
		ls->chars = ls->chars->n;
		free(tmp->str);
		free(tmp);
	}
}
