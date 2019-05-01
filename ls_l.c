/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_l.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llachgar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 00:20:46 by llachgar          #+#    #+#             */
/*   Updated: 2019/04/17 02:06:16 by llachgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_max_ll		*comp_max(struct stat st, t_max_ll *max)
{
	struct group	*gr;
	struct passwd	*pw;

	gr = getgrgid(st.st_gid);
	pw = getpwuid(st.st_uid);
	if (ft_calclen(st.st_nlink) > max->lnk)
		max->lnk = ft_calclen(st.st_nlink);
	if (ft_calclen(st.st_size) > max->size)
		max->size = ft_calclen(st.st_size);
	if (ft_strlen(gr->gr_name) > (size_t)max->grp)
		max->grp = ft_strlen(gr->gr_name);
	if (ft_strlen(pw->pw_name) > (size_t)max->usr)
		max->usr = ft_strlen(pw->pw_name);
	if (file_type(st) == 'c' || file_type(st) == 'b')
	{
		if (ft_calclen(major(st.st_rdev)) > max->major)
			max->major = ft_calclen(major(st.st_rdev));
		if (ft_calclen(minor(st.st_rdev)) > max->minor)
			max->minor = ft_calclen(minor(st.st_rdev));
	}
	return (max);
}

void			get_link_path(char *path)
{
	char	link_path[PATH_MAX];
	int		size;

	size = readlink(path, link_path, PATH_MAX);
	link_path[size] = '\0';
	ft_printf(" -> %s", link_path);
}

void			get_info(char *file, t_max_ll *max, t_ls *ls, int i)
{
	struct stat		st;
	struct group	*gr;
	struct passwd	*pw;
	char			*nbr;

	if (lstat(file, &st) == 0)
	{
		gr = getgrgid(st.st_gid);
		pw = getpwuid(st.st_uid);
		put_mode(st, file);
		nbr = ft_itoa_base(st.st_nlink, 10);
		put_space(max->lnk, nbr, 0);
		put_space(max->usr, pw->pw_name, 1);
		put_space(max->grp, gr->gr_name, 1);
		get_size(st, max->size, max->major);
		get_time(st.st_mtime);
		ft_printf("%s", ls->tab[i].d_name);
		if (file_type(st) == 'l')
			get_link_path(file);
		ft_putchar('\n');
		free(nbr);
	}
}

void			total(t_ls *ls, int cunt)
{
	char		*path;
	int			i;
	int			total;
	struct stat	st;

	i = 0;
	total = 0;
	while (i < cunt)
	{
		path = ft_strjoin_f(ls->path, "/", 0, 0);
		path = ft_strjoin_f(path, ls->tab[i].d_name, 1, 0);
		if (lstat(path, &st) == 0)
			total += st.st_blocks;
		free(path);
		i++;
	}
	if (cunt > 0)
		ft_printf("total %d\n", total);
}

int				ls_l(t_ls *ls, t_free_tab **tabs)
{
	float		max_l;
	int			cunt;
	int			i;
	t_max_ll	*max;

	cunt = 0;
	max_l = max_len(ls, &cunt);
	max_l = next_8(max_l);
	ls->col_numb = ls->win_max.ws_col / max_l;
	if ((ls->tab = stock_directories(ls, cunt, tabs)) == NULL)
		return (ft_printf("ls: %s: %s\n", ls->path, strerror(errno)) * -1);
	if (ls->flags.t)
		ls_t(*ls, ls->tab, cunt);
	else
		ls->tab = ascii_order(ls->tab, cunt);
	if (ls->flags.r)
		ft_reverse(ls, cunt);
	i = -1;
	max = get_max(ls, cunt);
	total(ls, cunt);
	while (++i < cunt)
		put_ls_l(ls, i, max);
	free(max);
	return (cunt);
}
